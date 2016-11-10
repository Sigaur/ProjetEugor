#include "Carte.h"

Carte::Carte()
{
	this->no_of_cols = 50;
	this->no_of_rows = 50;


	this->m_matrix.resize(no_of_rows, std::vector<Tile>(no_of_cols));

}

Carte::~Carte()
{
}

void Carte::displayCarte(Movable player)
{
	/*
	for (int j = 0; j < no_of_rows; j++)
	{
		for (int i = 0; i < no_of_cols; i++)
		{
			display(i, j);
		}
	}
	*/
	int minY, maxY, minX, maxX;
	if (player.getPosY() - 6 < 0)
		minY = 0;
	else
		minY = player.getPosY() - 6;
	
	if (player.getPosY() + 7 > no_of_rows)
		maxY = no_of_rows;
	else
		maxY = player.getPosY() + 7;

	if (player.getPosX() - 6 < 0)
		minX = 0;
	else
		minX = player.getPosX() - 6;

	if (player.getPosX() + 7 > no_of_cols)
		maxX = no_of_cols;
	else
		maxX = player.getPosX() + 7;


	for (int j = minY; j < maxY; j++)
	{
		for (int i = minX; i < maxX; i++)
		{
			display(i, j);
		}
	}
}

void Carte::display(int x, int y)
{
	this->m_display.tileDisplay(this->m_matrix[x][y]);
}

void Carte::displayDoors()
{
	for (int i = 0; i < m_doors.size(); i++)
	{
		display(this->m_doors[i].posX, this->m_doors[i].posY);
	}
}

void Carte::setDoors(std::vector<bool> doors)
{
	for (int i = 0; i < doors.size() && i < this->m_doors.size(); i++)
	{
		if (doors[i])
		{
			//std::cout << "opening door" << this->m_doors[i].posX << "/" << this->m_doors[i].posY << std::endl;
			this->m_matrix[this->m_doors[i].posX][this->m_doors[i].posY].openDoor();
		}
	}
}

std::vector<bool> Carte::saveDoors()
{
	std::vector <bool> temp;
	for (int i = 0; i < this->m_doors.size(); i++)
	{
		if (this->m_matrix[this->m_doors[i].posX][this->m_doors[i].posY].getType() == door_open)
		{
			temp.push_back(true);
		}
		else
		{
			temp.push_back(false);
		}
	}
	return temp;
}

void Carte::setTest()
{
	for (int j = 0; j < no_of_rows; j++)
	{
		for (int i = 0; i < no_of_cols; i++)
		{
			this->m_matrix[i][j].set(0, i, j);
			this->m_matrix[i][j].setType(unknow);
			this->m_matrix[i][j].fulling();
		}
	}
	wallConstructible.clear();
}

void Carte::fulling(int x1, int y1, int x2, int y2)
{
	swapping(x1, x2);
	swapping(y1, y2);
	for (int j = y1; j <= y2; j++)
	{
		for (int i = x1; i <= x2; i++)
		{
			this->m_matrix[i][j].fulling();
		}
	}
}

void Carte::digging(int x1, int y1, int x2, int y2, tileType type)
{
	swapping(x1, x2);
	swapping(y1, y2);
	for (int j = y1; j <= y2; j++)
	{
		for (int i = x1; i <= x2; i++)
		{
			if ((x1 > 1 && x1 < no_of_cols - 2) && (x2 > 1 && x2 < no_of_cols - 2)
				&& (y1 > 1 && y1 < no_of_rows - 2) && (y2 > 1 && y2 < no_of_rows - 2))
			{
				this->m_matrix[i][j].digging();
				this->m_matrix[i][j].setType(type);
			}
			else return;
		}
	}
	
	//std::cout << "DIGGING" << std::endl;
}

bool Carte::inBound(int x1, int y1, int x2, int y2)
{
	if ((x1 > 1 && x1 < no_of_cols - 1) && (x2 > 1 && x2 < no_of_cols - 1)
		&& (y1 > 1 && y1 < no_of_rows - 1) && (y2 > 1 && y2 < no_of_rows - 1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool Carte::inBound(int x1, int y1)
{
	if ((x1 > 1 && x1 < no_of_cols - 1) && (y1 > 1 && y1 < no_of_rows - 1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Carte::pushingBack(std::vector<Tile> &vec, Tile tile)
{
	int i = 0, in = 0;
	if (vec.size() == 0)
	{
		vec.push_back(tile);
	}
	else
	{
		do
		{
			if (tile.getX() == vec[i].getX() && tile.getY() == vec[i].getY())
			{
				return;
			}
			i++;
		}while (i < vec.size());
	}
	vec.push_back(tile);
}

void Carte::swapping(int &x1, int &x2)
{
	int temp;
	if (x1 > x2)
	{
		temp = x1;
		x1 = x2;
		x2 = temp;
	}
}

bool Carte::isFull(int x1, int y1, int x2, int y2)
{
	bool response = 1;
	if (inBound(x1 + 1, y1 + 1) && inBound(x1 - 1, y1 - 1) && inBound(x2 + 1, y2 + 1) && inBound(x2 - 1, y2 - 1))
	{
		swapping(x1, x2);
		swapping(y1, y2);
		for (int j = y1 - 1; j <= y2 + 1; j++)
		{
			for (int i = x1 - 1; i <= x2 + 1; i++)
			{
				//std::cout << "IS FULL?" << std::endl;
				if (!this->m_matrix[i][j].isFull())
				{
					//std::cout << i << "/" << j << std::endl;
					response = 0;
				}
			}
		}
	}
	else
	{
		response = 0;
	}
	return response;
}

bool Carte::isWalkable(int x1, int y1)
{
	return this->m_matrix[x1][y1].isWalkable();
}

bool Carte::walking(int x1, int y1)
{
	getInteraction(x1, y1);
	return this->m_matrix[x1][y1].walking();
}

void Carte::getInteraction(int x1, int y1)///MANAGING INTERACTIONS WITH MOVABLE OBJECTS(DOORS FOR EXEMPLE)
{
	for (int i = 0; i < this->m_doors.size(); i++)
	{
		if (x1 == this->m_doors[i].posX && y1 == this->m_doors[i].posY)
		{

		}
	}
}

tileType Carte::getType(int x1, int y1)
{
	return this->m_matrix[x1][y1].getType();
}

Position Carte::getRandomFreeSpace()
{
	Position temp;
	temp.posX = 0;
	temp.posY = 0;
	while (true)
	{
		temp.posX = rand() % this->no_of_cols;
		temp.posY = rand() % this->no_of_rows;
		if (!this->m_matrix[temp.posX][temp.posY].isFull())
		{
			return temp;
		}
	}
}

Position Carte::getPositionFromType(tileType type)
{
	Position temp;
	temp.posX = 0;
	temp.posY = 0;
	for (int j = 0; j < no_of_rows; j++)
	{
		for (int i = 0; i < no_of_cols; i++)
		{
			if (this->m_matrix[i][j].getType() == type)
			{
				temp.posX = i;
				temp.posY = j;
			}
		}
	}
	return temp;
}

std::string Carte::roomTypeGenerator(int &x1, int &y1, int &x2, int &y2, std::string from)
{
	int random = rand() % 10 + 1;
	int vertical;
	std::string roomType="error";
	
	if (random < 0)//corridor Type
	{
		roomType = "corridor";
		vertical = rand() % 2;
		do
		{
			x1 = 3;
		} while (x1 > no_of_cols - 2 || x1 < 1);
		do
		{
			y1 = 3;
		} while (y1 > no_of_rows - 2 || y1 < 1);
		do
		{
			if (vertical == 1)
			{
				x2 = x1;
			}
			else
			{
				x2 = x1 + rand() % 10 + 2;
			}
		} while (x2 > no_of_cols - 2 || x2 < 1);
		do
		{
			if (vertical == 1)
			{
				y2 = y1 + rand() % 10 + 2;
			}
			else
			{
				y2 = y1;
			}
		} while (y2 > no_of_rows - 2 || y2 < 1);
	}
	else//Room Type
	{
		roomType = "room";
		do
		{
			x1 = rand() % 10;
		} while (x1 > no_of_cols - 2 || x1 < 1);
		do
		{
			y1 = rand() % 10;
		} while (y1 > no_of_rows - 2 || y1 < 1);
		do
		{
			x2 = x1 + rand() % 7 + 1;
		} while (x2 > no_of_cols - 2 || x2 < 1);
		do
		{
			y2 = y1 + rand() % 7 + 1;
		} while (y2 > no_of_rows - 2 || y2 < 1);
	}
	//std::cout << "roomCoordinate" << x1 << "/" << y1 << "     " << x2 << "/" << y2 << std::endl;
	swapping(x1, x2);
	swapping(y1, y2);
	return roomType;
}

void Carte::roomTest(int paraX, int paraY, int corrX, int corrY, std::string from)
{
	int x1;
	int y1;
	int x2;
	int y2;
	int entreeX = 0, entreeY = 0, random;
	int decalageX, decalageY;
	bool continu = 1;
	Position door;
	std::vector<Tile> wallUp;
	std::vector<Tile> wallDown;
	std::vector<Tile> wallRight;
	std::vector<Tile> wallLeft;

	if (corrX == 0 && corrY == 0)
	{
		return;
	}
	

	std::string roomType = roomTypeGenerator(x1, y1, x2, y2, from);
	//while (continu)
	//{
	if(roomType == "room")
	{
		//std::cout << x1 << "/" << y1 <<"     "<< x2 << "/" << y2 << std::endl;
		for (int i = x1; i <= x2; i++)
		{
			pushingBack(wallUp, this->m_matrix[i][y1]);
			pushingBack(wallDown, this->m_matrix[i][y2]);
			//temp.push_back(this->m_matrix[i][y1]);
			//temp.push_back(this->m_matrix[i][y2]);
		}
		for (int j = y1; j <= y2; j++)
		{
			pushingBack(wallRight, this->m_matrix[x1][j]);
			pushingBack(wallLeft, this->m_matrix[x2][j]);
			//temp.push_back(this->m_matrix[x1][j]);
			//temp.push_back(this->m_matrix[x2][j]);
		}
		if (from == "down")
		{
			random = rand() % wallUp.size();
			entreeX = wallUp[random].getX();
			entreeY = wallUp[random].getY();
		}
		else if (from == "up")
		{
			random = rand() % wallDown.size();
			entreeX = wallDown[random].getX();
			entreeY = wallDown[random].getY();
		}
		else if (from == "left")
		{
			random = rand() % wallRight.size();
			entreeX = wallRight[random].getX();
			entreeY = wallRight[random].getY();
		}
		else if (from == "right")
		{
			random = rand() % wallLeft.size();
			entreeX = wallLeft[random].getX();
			entreeY = wallLeft[random].getY();
		}


		decalageX = entreeX - paraX;
		decalageY = entreeY - paraY;

		x1 -= decalageX;
		x2 -= decalageX;
		y1 -= decalageY;
		y2 -= decalageY;
		//std::cout << "Is full" << x1 << "/" << y1 << "   " << x2 << "/" << y2<< std::endl;
		if (isFull(x1, y1, x2, y2))
		{
			//std::cout << "Digging" << std::endl;
			digging(x1, y1, x2, y2, brickFloor);
			for (int i = x1; i <= x2; i++)
			{
				pushingBack(wallConstructible, this->m_matrix[i][y1]);
				pushingBack(wallConstructible, this->m_matrix[i][y2]);
				//this->m_matrix[i][y1].set(1, 3);
				//this->m_matrix[i][y2].set(1, 3);
				//wallConstructible.push_back(this->m_matrix[i][y1]);
				//wallConstructible.push_back(this->m_matrix[i][y2]);
			}
			for (int j = y1 + 1; j < y2; j++)
			{
				pushingBack(wallConstructible, this->m_matrix[x1][j]);
				pushingBack(wallConstructible, this->m_matrix[x2][j]);
				//this->m_matrix[x1][j].set(1, 3);
				//this->m_matrix[x2][j].set(1, 3);
				//wallConstructible.push_back(this->m_matrix[x1][j]);
				//wallConstructible.push_back(this->m_matrix[x2][j]);
			}
			this->m_matrix[corrX][corrY].digging();
			//this->m_matrix[corrX][corrY].set(1);
			this->m_matrix[corrX][corrY].setType(door_closed);
			door.posX = corrX;
			door.posY = corrY;
			this->m_doors.push_back(door);

			for (int i = 0; i < wallConstructible.size(); i++)
			{
				if (paraX == wallConstructible[i].getX() && paraY == wallConstructible[i].getY())
				{
					//std::cout << "Erase" << std::endl;
				}
			}
		}
	}
	wallUp.clear();
	wallDown.clear();
	wallRight.clear();
	wallLeft.clear();
}
/*
void Carte::corridorTest(int paraX, int paraY, int corrX, int corrY, bool vertical)
{
	int x1;
	int y1;
	int x2;
	int y2;
	int entreeX, entreeY, random;
	int decalageX, decalageY;
	bool continu = 1;
	std::vector<Tile> temp;


	//while (continu)
	//{
	
	//std::cout << x1 << "/" << y1 <<"     "<< x2 << "/" << y2 << std::endl;
	for (int i = x1; i <= x2; i++)
	{
		pushingBack(temp, this->m_matrix[i][y1]);
		pushingBack(temp, this->m_matrix[i][y2]);
		//temp.push_back(this->m_matrix[i][y1]);
		//temp.push_back(this->m_matrix[i][y2]);
	}
	for (int j = y1 + 1; j < y2; j++)
	{
		pushingBack(temp, this->m_matrix[x1][j]);
		pushingBack(temp, this->m_matrix[x2][j]);
		//temp.push_back(this->m_matrix[x1][j]);
		//temp.push_back(this->m_matrix[x2][j]);
	}
	random = rand() % temp.size();
	entreeX = temp[random].getX();
	entreeY = temp[random].getY();

	decalageX = entreeX - paraX;
	decalageY = entreeY - paraY;

	x1 -= decalageX;
	x2 -= decalageX;
	y1 -= decalageY;
	y2 -= decalageY;
	//std::cout << "Is full" << x1 << "/" << y1 << "   " << x2 << "/" << y2<< std::endl;
	if (isFull(x1, y1, x2, y2))
	{
		//std::cout << "Digging" << std::endl;
		digging(x1, y1, x2, y2);
		pushingBack(wallConstructible, this->m_matrix[x1][y1]);
		pushingBack(wallConstructible, this->m_matrix[x2][y2]);
		this->m_matrix[x1][y1].set(1, 3);
		this->m_matrix[x2][y2].set(1, 3);
		this->m_matrix[corrX][corrY].digging();
		this->m_matrix[corrX][corrY].set(1, 4);
	}
	//}
}
*/
void Carte::dungeonTest(int level)
{
	Position randomPosition;
	int exitX, exitY, random;
	int corrX = 0, corrY = 0;
	bool vertical = true;
	int x1 = (no_of_cols / 2) - 1, y1 = (no_of_rows / 2) - 1, x2 = (no_of_cols / 2) + 1, y2 = (no_of_rows / 2) + 1;
	std::string from = "prob";
	digging(x1, y1, x2, y2, brickFloor);
	
	for (int i = x1; i <= x2; i++)
	{
		pushingBack(wallConstructible, this->m_matrix[i][y1]);
		pushingBack(wallConstructible, this->m_matrix[i][y2]);
		//this->m_matrix[i][y1].set(1, 3);
		//this->m_matrix[i][y2].set(1, 3);
		//wallConstructible.push_back(this->m_matrix[i][y1]);
		//wallConstructible.push_back(this->m_matrix[i][y2]);
	}
	for (int j = y1 + 1; j < y2; j++)
	{
		pushingBack(wallConstructible, this->m_matrix[x1][j]);
		pushingBack(wallConstructible, this->m_matrix[x2][j]);
		//this->m_matrix[x1][j].set(1, 3);
		//this->m_matrix[x2][j].set(1, 3);
		//wallConstructible.push_back(this->m_matrix[x1][j]);
		//wallConstructible.push_back(this->m_matrix[x2][j]);
	}
	


	for (int i = 0; i < 500; i++)
	{
		random = rand() % wallConstructible.size();
		exitX = wallConstructible[random].getX();
		exitY = wallConstructible[random].getY();
		
		if (inBound(exitX + 2, exitY + 2) && inBound(exitX - 2, exitY - 2))
		{
			random = rand() % 4 + 1;
			switch (random)
			{
			default:
				break;
			case 1:
				if (!this->m_matrix[exitX + 2][exitY].isFull())
				{
					exitX += 4;
					corrX = exitX - 1;
					corrY = exitY;
					vertical = 1;
					from = "left";
				}
				break;
			case 2:
				if (!this->m_matrix[exitX - 2][exitY].isFull())
				{
					exitX -= 4;
					corrX = exitX + 1;
					corrY = exitY;
					vertical = 1;
					from = "right";
				}
				break;
			case 3:
				if (!this->m_matrix[exitX][exitY + 2].isFull())
				{
					exitY += 4;
					corrX = exitX;
					corrY = exitY - 1;
					vertical = 0;
					from = "down";
				}
				break;
			case 4:
				if (!this->m_matrix[exitX][exitY - 2].isFull())
				{
					exitY -= 4;
					corrX = exitX;
					corrY = exitY + 1;
					vertical = 0;
					from = "up";
				}
				break;
				//not used after this point for now!!!!!!!!!!
			case 5:
				if (!this->m_matrix[exitX + 2][exitY + 2].isFull())
				{
					exitX += 4;
					exitY += 4;
					corrX = exitX - 1;
					corrY = exitY - 1;
					vertical = 1;
				}
				break;
			case 6:
				if (!this->m_matrix[exitX - 2][exitY + 2].isFull())
				{
					exitX -= 4;
					exitY += 4;
					corrX = exitX + 1;
					corrY = exitY - 1;
					vertical = 1;
				}
				break;
			case 7:
				if (!this->m_matrix[exitX + 2][exitY - 2].isFull())
				{
					exitX += 4;
					exitY -= 4;
					corrX = exitX - 1;
					corrY = exitY + 1;
					vertical = 0;
				}
				break;
			case 8:
				if (!this->m_matrix[exitX - 2][exitY - 2].isFull())
				{
					exitX -= 4;
					exitY -= 4;
					corrX = exitX + 1;
					corrY = exitY + 1;
					vertical = 0;
				}
				break;
			}
			//} while ((exitX > no_of_cols - 1 || exitX < 1) || (exitY > no_of_rows - 1 || exitY < 1));
		}
		roomTest(exitX, exitY, corrX, corrY, from);
		//wallConstructible.erase(wallConstructible.begin() + random);
		//system("PAUSE");
		//roomTest(rand()%50, rand() % 50);
	}
	wallConstructible.clear();
	randomPosition = this->getRandomFreeSpace();
	this->m_matrix[randomPosition.posX][randomPosition.posY].setType(stairsDown);
	if (level > 0)
	{
		randomPosition = this->getRandomFreeSpace();
		this->m_matrix[randomPosition.posX][randomPosition.posY].setType(stairsUp);
	}
}
