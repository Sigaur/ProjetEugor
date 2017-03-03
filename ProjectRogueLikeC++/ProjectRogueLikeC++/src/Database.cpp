#include "Database.h"



Database::Database()
{
	this->m_carte = Carte();
	this->m_player = Movable(1, "Player", 25, 25, 2);
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
	this->m_ennemis.push_back(Ennemi(1, "Premier Ennemi", posEnnemi.posX, posEnnemi.posY, 1));
}

void Database::displayAll()
{
	displayCarte();
	displayEntities();
}

void Database::displayAll(int x, int y)
{
	displayCarte(x, y);
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
{
	this->m_display.entityDisplay(this->m_player);
	for (int i = 0; i < this->m_ennemis.size(); i++)
	{
		for (int j = 0; j < this->m_visible.size(); j++)
		{
			if (this->m_ennemis[i].getPosX() == this->m_visible[j].posX &&
				this->m_ennemis[i].getPosY() == this->m_visible[j].posY)
			{
				this->m_display.entityDisplay(this->m_ennemis[i]);
			}
		}
	}
}