#include "Database.h"



Database::Database()
{
	Position positionPlayer;
	positionPlayer.posX = 25;
	positionPlayer.posY = 25;
	this->m_carte = Carte();
	this->m_player = Movable(1, "Player", positionPlayer, 2);
	this->m_display = Display();

}

Database::~Database()
{

}


void Database::createLevel(int seed)
{
	this->m_carte.setTest();
	this->m_carte.dungeonTest(seed);

	//creating ennemis
	Position posEnnemi = this->m_carte.getRandomFreeSpace();
	Position objectif;
	objectif.posX = 24;
	objectif.posY = 24;
	//this->m_ennemis.push_back(new Ennemi(1, posEnnemi.posX, posEnnemi.posY, skeleton));
	this->m_ennemis.push_back(new Ennemi(1, objectif, skeleton, station, objectif));
	//this->m_carte.setWalkable(posEnnemi.posX, posEnnemi.posY, 0);

	for (size_t i = 0; i < 10; i++)
	{
		Position posEnnemi = this->m_carte.getRandomFreeSpace();
		this->m_ennemis.push_back(new Ennemi(1, posEnnemi, skeleton, station, objectif));
	}
}

void Database::displayAll()
{
	displayCarte();
	updateEnnemies();
	displayEntities();
}

void Database::displayAll(int x, int y)
{
	displayCarte(x, y);
	updateEnnemies();
	displayEntities();
}

void Database::displayCarte(int initX, int initY)
{
	int minY, maxY, minX, maxX;
	int no_of_rows = this->m_carte.getNoRows(), no_of_cols = this->m_carte.getNoCols();

	if (initY - 12 < 0)
		minY = 0;
	else
		minY = initY - 12;

	if (initY + 13 > no_of_rows)
		maxY = no_of_rows;
	else
		maxY = initY + 13;

	if (initX - 12 < 0)
		minX = 0;
	else
		minX = initX - 12;

	if (initX + 13 > no_of_cols)
		maxX = no_of_cols;
	else
		maxX = initX + 13;

	//////////////////////Temp Sends Min/Max x/y to FOV Function///////////////////

	for (int j = minY; j < maxY; j++)
	{
		for (int i = minX; i < maxX; i++)
		{
			if (this->m_carte.m_matrix[i][j].isExplored())
				displayTile(i, j, true);
		}
	}

	FOV(minX, maxX, minY, maxY);
}

void Database::displayCarte()
{
	int minY, maxY, minX, maxX;
	int no_of_rows = this->m_carte.getNoRows(), no_of_cols = this->m_carte.getNoCols();

	if (this->m_player.getPosY() - 12 < 0)
		minY = 0;
	else
		minY = this->m_player.getPosY() - 12;

	if (this->m_player.getPosY() + 13 > no_of_rows)
		maxY = no_of_rows;
	else
		maxY = this->m_player.getPosY() + 13;

	if (this->m_player.getPosX() - 12 < 0)
		minX = 0;
	else
		minX = this->m_player.getPosX() - 12;

	if (this->m_player.getPosX() + 13 > no_of_cols)
		maxX = no_of_cols;
	else
		maxX = this->m_player.getPosX() + 13;

	//////////////////////Temp Sends Min/Max x/y to FOV Function///////////////////
	
	for (int j = minY; j < maxY; j++)
	{
		for (int i = minX; i < maxX; i++)
		{
			if(this->m_carte.m_matrix[i][j].isExplored())
				displayTile(i, j, true);
		}
	}
	
	FOV(minX, maxX, minY, maxY);
}

void Database::FOV(int minX, int maxX, int minY, int maxY)
{
	m_visible.clear();
	/*
	Position posTemp;
	std::vector<Position> lineRight;
	std::vector<Position> lineDown;
	std::vector<Position> lineLeft;
	std::vector<Position> lineUp;

	int initialX = m_player.getPosX();
	int initialY = m_player.getPosY();

	int view = m_player.getView();

	///////Test single direction : Right side/////
	///////Add Direction!!!!!!!!!!!!!

	////Initialisation
	posTemp = m_player.getPosition();
	
		////First Line
	//Right
	for (int i = 0; i <= view; i++)
	{
		if (initialX + i < maxX)
		{
			posTemp.posX = initialX + i;
			posTemp.posY = initialY;

			if (!m_carte.isSeeThr(posTemp.posX, posTemp.posY))
				i += (view + 1);
			else
				lineRight.push_back(posTemp);

			m_visible.push_back(posTemp);
			displayTile(posTemp, false);
			m_carte.m_matrix[posTemp.posX][posTemp.posY].setExplored(true);
		}
	}
	//Left
	for (int i = 0; i <= view; i++)
	{
		if (initialX - i > minX)
		{
			posTemp.posX = initialX - i;
			posTemp.posY = initialY;

			if (!m_carte.isSeeThr(posTemp.posX, posTemp.posY))
				i += (view + 1);
			else
				lineLeft.push_back(posTemp);

			m_visible.push_back(posTemp);
			displayTile(posTemp, false);
			m_carte.m_matrix[posTemp.posX][posTemp.posY].setExplored(true);
		}
	}
	//Down
	for (int i = 0; i <= view; i++)
	{
		if (initialY + i < maxY)
		{
			posTemp.posX = initialX;
			posTemp.posY = initialY + i;

			if (!m_carte.isSeeThr(posTemp.posX, posTemp.posY))
				i += (view + 1);
			else
				lineDown.push_back(posTemp);

			m_visible.push_back(posTemp);
			displayTile(posTemp, false);
			m_carte.m_matrix[posTemp.posX][posTemp.posY].setExplored(true);
		}
	}
	//Up
	for (int i = 0; i <= view; i++)
	{
		if (initialY - i > minY)
		{
			posTemp.posX = initialX;
			posTemp.posY = initialY - i;

			if (!m_carte.isSeeThr(posTemp.posX, posTemp.posY))
				i += (view + 1);				
			else
				lineUp.push_back(posTemp);

			m_visible.push_back(posTemp);
			displayTile(posTemp, false);
			m_carte.m_matrix[posTemp.posX][posTemp.posY].setExplored(true);
		}
	}
	

	////Iterative Diagonals
	///Right
	for (int x = 0; x < lineRight.size(); x++)
	{
		initialX = lineRight[x].posX;
		initialY = lineRight[x].posY;
		//RightUp
		for (int i = 1; i <= view - x; i++)
		{
			if ((initialX + i < maxX) && (initialY - i > minY))
			{
				posTemp.posX = initialX + i;
				posTemp.posY = initialY - i;

				if (!m_carte.isSeeThr(posTemp.posX, posTemp.posY))
					i += (view + 1);

				m_visible.push_back(posTemp);
				displayTile(posTemp, false);
				m_carte.m_matrix[posTemp.posX][posTemp.posY].setExplored(true);
			}
		}
		//RightDown
		for (int i = 1; i <= view - x; i++)
		{
			if ((initialX + i < maxX) && (initialY + i < maxY))
			{
				posTemp.posX = initialX + i;
				posTemp.posY = initialY + i;

				if (!m_carte.isSeeThr(posTemp.posX, posTemp.posY))
					i += (view + 1);

				m_visible.push_back(posTemp);
				displayTile(posTemp, false);
				m_carte.m_matrix[posTemp.posX][posTemp.posY].setExplored(true);
			}
		}
	}
	///Left
	for (int x = 0; x < lineLeft.size(); x++)
	{
		initialX = lineLeft[x].posX;
		initialY = lineLeft[x].posY;
		//LeftUp
		for (int i = 1; i <= view - x; i++)
		{
			if ((initialX - i > minX) && (initialY - i > minY))
			{
				posTemp.posX = initialX - i;
				posTemp.posY = initialY - i;

				if (!m_carte.isSeeThr(posTemp.posX, posTemp.posY))
					i += (view + 1);

				m_visible.push_back(posTemp);
				displayTile(posTemp, false);
				m_carte.m_matrix[posTemp.posX][posTemp.posY].setExplored(true);
			}
		}
		//LeftDown
		for (int i = 1; i <= view - x; i++)
		{
			if ((initialX - i < maxX) && (initialY + i < maxY))
			{
				posTemp.posX = initialX - i;
				posTemp.posY = initialY + i;

				if (!m_carte.isSeeThr(posTemp.posX, posTemp.posY))
					i += (view + 1);

				m_visible.push_back(posTemp);
				displayTile(posTemp, false);
				m_carte.m_matrix[posTemp.posX][posTemp.posY].setExplored(true);
			}
		}
	}
	///Up
	for (int x = 0; x < lineUp.size(); x++)
	{
		initialX = lineUp[x].posX;
		initialY = lineUp[x].posY;
		//LeftUp
		for (int i = 1; i <= view - x; i++)
		{
			if ((initialX - i > minX) && (initialY - i > minY))
			{
				posTemp.posX = initialX - i;
				posTemp.posY = initialY - i;

				if (!m_carte.isSeeThr(posTemp.posX, posTemp.posY))
					i += (view + 1);

				m_visible.push_back(posTemp);
				displayTile(posTemp, false);
				m_carte.m_matrix[posTemp.posX][posTemp.posY].setExplored(true);
			}
		}
		//RightUp
		for (int i = 1; i <= view - x; i++)
		{
			if ((initialX + i < maxX) && (initialY - i < maxY))
			{
				posTemp.posX = initialX + i;
				posTemp.posY = initialY - i;

				if (!m_carte.isSeeThr(posTemp.posX, posTemp.posY))
					i += (view + 1);

				m_visible.push_back(posTemp);
				displayTile(posTemp, false);
				m_carte.m_matrix[posTemp.posX][posTemp.posY].setExplored(true);
			}
		}
	}
	///Down
	for (int x = 0; x < lineDown.size(); x++)
	{
		initialX = lineDown[x].posX;
		initialY = lineDown[x].posY;
		//LeftDown
		for (int i = 1; i <= view - x; i++)
		{
			if ((initialX - i > minX) && (initialY + i > minY))
			{
				posTemp.posX = initialX - i;
				posTemp.posY = initialY + i;

				if (!m_carte.isSeeThr(posTemp.posX, posTemp.posY))
					i += (view + 1);

				m_visible.push_back(posTemp);
				displayTile(posTemp, false);
				m_carte.m_matrix[posTemp.posX][posTemp.posY].setExplored(true);
			}
		}
		//RightDown
		for (int i = 1; i <= view - x; i++)
		{
			if ((initialX + i < maxX) && (initialY + i < maxY))
			{
				posTemp.posX = initialX + i;
				posTemp.posY = initialY + i;

				if (!m_carte.isSeeThr(posTemp.posX, posTemp.posY))
					i += (view + 1);

				m_visible.push_back(posTemp);
				displayTile(posTemp, false);
				m_carte.m_matrix[posTemp.posX][posTemp.posY].setExplored(true);
			}
		}
	}
	*/
	
Position tempPos;

	for (int x = minX; x < maxX; x++)
	{
		for (int y = minY; y < maxY; y++)
		{
			tempPos.posX = x;
			tempPos.posY = y;
			if (this->m_carte.getDistance(tempPos, this->m_player.getPosition()) <= 7)
			{
				if (this->m_carte.lineOfSight(this->m_player.getPosition(), tempPos))
				{
					m_visible.push_back(tempPos);
					displayTile(tempPos, false);
					m_carte.m_matrix[tempPos.posX][tempPos.posY].setExplored(true);
				}
			}
			
		}
	}
	
}

void Database::displayTile(int x, int y, bool fade)
{
	this->m_display.tileDisplay(this->m_carte.m_matrix[x][y], fade);
}

void Database::displayTile(Position position, bool fade)
{
	this->m_display.tileDisplay(this->m_carte.m_matrix[position.posX][position.posY], fade);
}

void Database::displayEntities()
{	this->m_display.entityDisplay(this->m_player);
	for (int i = 0; i < this->m_visibleEnnemies.size(); i++)
	{
		this->m_display.entityDisplay(this->m_visibleEnnemies[i]);
	}
}

void Database::updateEnnemies()
{
	this->m_visibleEnnemies.clear();
	for (int i = 0; i < this->m_ennemis.size(); i++)
	{
		if (!m_ennemis[i]->isAlive())
		{
			m_ennemis[i]->~Ennemi();
			this->m_ennemis.erase(this->m_ennemis.begin() + i);
		}		
	}
	for (int i = 0; i < this->m_ennemis.size(); i++)
	{
		for (int j = 0; j < this->m_visible.size(); j++)
		{
			if (this->m_ennemis[i]->getPosX() == this->m_visible[j].posX &&
				this->m_ennemis[i]->getPosY() == this->m_visible[j].posY)
			{
				this->m_visibleEnnemies.push_back(this->m_ennemis[i]);

				/////Temporary
				if ((this->m_carte.getDistance(this->m_ennemis[i]->getPosition(), this->m_player.getPosition())) <= 4)
				{
					if (this->m_carte.lineOfSight(this->m_ennemis[i]->getPosition(), this->m_player.getPosition()))
					{
						this->m_ennemis[i]->setState(track);
						this->m_ennemis[i]->setObjectif(this->m_player.getPosition());
					}						
					else if (this->m_ennemis[i]->getObjectif().posX == this->m_ennemis[i]->getPosition().posX &&
								this->m_ennemis[i]->getObjectif().posY == this->m_ennemis[i]->getPosition().posY)
						this->m_ennemis[i]->setState(alert);
				}
				else
					this->m_ennemis[i]->setState(station);
			}
		}
	}
}

bool Database::getInteraction(int x1, int y1)
{
	for (int i = 0; i < this->m_visibleEnnemies.size(); i++)
	{
		if (x1 == this->m_visibleEnnemies[i]->getPosX() && y1 == this->m_visibleEnnemies[i]->getPosY())
		{
			/////////////Interaction with ennemi
			this->m_visibleEnnemies[i]->takeDamage(10);
			//return (!this->m_visibleEnnemies[i]->isAlive());
			return false;
		}
	}
	if (x1 == this->m_player.getPosX() && y1 == this->m_player.getPosY())
	{
		return false;
	}
	return true;
}

void Database::ennemiesMouvement()
{
	Position tempObjectif;
	Position tempPosInit;
	Position tempPosition;

	Ennemi *tempEnnemi;

	int xDiff, yDiff;
	//std::cout << "Ennemies Mouvement" << std::endl;
	for (int i = 0; i < this->m_ennemis.size(); i++)
	{
		tempEnnemi = this->m_ennemis[i];
		switch (tempEnnemi->getState())
		{
		case track:
			//std::cout << "Ennemies Mouvement1" << std::endl;
			tempPosition = tempEnnemi->getPosition();
			tempObjectif = tempEnnemi->getObjectif();
			xDiff = tempObjectif.posX - tempPosition.posX;
			yDiff = tempObjectif.posY - tempPosition.posY;


			//std::cout << "xDiff" << xDiff << "yDiff" << yDiff << std::endl;

			if (xDiff > 0)
			{

				std::cout << "trace 1" << std::endl;
				if (yDiff > 0)
				{
					if (moveCheck(tempPosition, downRight))
					{
						std::cout << "downRight" << std::endl;
						tempEnnemi->moveDownRight();
					}
				}
				else if (yDiff < 0)
				{
					if (moveCheck(tempPosition, upRight))
					{
						std::cout << "upRight" << std::endl;
						tempEnnemi->moveUpRight();
					}
				}
				else
					if (moveCheck(tempPosition, right))
					{
						std::cout << "right" << std::endl;
						tempEnnemi->moveRight();
					}
			}
			else if (xDiff < 0)
			{
				if (yDiff > 0)
				{
					if (moveCheck(tempPosition, downLeft))
					{
						std::cout << "downLeft" << std::endl;
						tempEnnemi->moveDownLeft();
					}
				}
				else if (yDiff < 0)
				{
					if (moveCheck(tempPosition, upLeft))
					{
						std::cout << "upLeft" << std::endl;
						tempEnnemi->moveUpLeft();
					}
				}
				else
					if (moveCheck(tempPosition, left))
					{
						std::cout << "left" << std::endl;
						tempEnnemi->moveLeft();
					}
			}
			else
			{
				if (yDiff > 0)
				{
					if (moveCheck(tempPosition, down))
					{
						std::cout << "down" << std::endl;
						tempEnnemi->moveDown();
					}
				}
				else if (yDiff < 0)
				{
					if (moveCheck(tempPosition, up))
					{
						std::cout << "up" << std::endl;
						tempEnnemi->moveUp();
					}
				}
			}
			break;
		}
		if ((tempEnnemi->getPreviousPosition().posX == tempEnnemi->getPosition().posX) &&
			(tempEnnemi->getPreviousPosition().posX == tempEnnemi->getPosition().posX))
		{

		}
	}
	
}

bool Database::moveCheck(Position posInitial, direction move)
{
	switch (move)
	{
	case right:

		std::cout << "trace2" << std::endl;
		if (this->m_carte.walking(posInitial.posX + 1, posInitial.posY))
		{
			if (this->getInteraction(posInitial.posX + 1, posInitial.posY))
			{
				return true;
			}
		}
		break;
	case left:
		if (this->m_carte.walking(posInitial.posX - 1, posInitial.posY))
		{
			if (this->getInteraction(posInitial.posX - 1, posInitial.posY))
			{
				return true;
			}
		}
		break;
	case up:
		if (this->m_carte.walking(posInitial.posX, posInitial.posY - 1))
		{
			if (this->getInteraction(posInitial.posX, posInitial.posY - 1))
			{
				return true;
			}
		}
		break;
	case down:
		if (this->m_carte.walking(posInitial.posX, posInitial.posY + 1))
		{
			if (this->getInteraction(posInitial.posX, posInitial.posY + 1))
			{
				return true;
			}
		}
		break;
	case upRight:
		if (this->m_carte.walking(posInitial.posX + 1, posInitial.posY - 1))
		{
			if (this->getInteraction(posInitial.posX + 1, posInitial.posY - 1))
			{
				return true;
			}
		}
		break;
	case upLeft:
		if (this->m_carte.walking(posInitial.posX - 1, posInitial.posY - 1))
		{
			if (this->getInteraction(posInitial.posX - 1, posInitial.posY - 1))
			{
				return true;
			}
		}
		break;
	case downRight:
		if (this->m_carte.walking(posInitial.posX + 1, posInitial.posY + 1))
		{
			if (this->getInteraction(posInitial.posX + 1, posInitial.posY + 1))
			{
				return true;
			}
		}
		break;
	case downLeft:
		if (this->m_carte.walking(posInitial.posX - 1, posInitial.posY + 1))
		{
			if (this->getInteraction(posInitial.posX - 1, posInitial.posY + 1))
			{
				return true;
			}
		}
		break;
	default:
		return false;
		break;
	}
	return false;
}