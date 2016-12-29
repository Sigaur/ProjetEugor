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
}

void Database::displayAll()
{
	displayCarte();
	displayEntities();
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

	for (int j = minY; j < maxY; j++)
	{
		for (int i = minX; i < maxX; i++)
		{
			displayTile(i, j);
		}
	}
}

void Database::displayTile(int x, int y)
{
	this->m_display.tileDisplay(this->m_carte.m_matrix[x][y]);
}

void Database::displayEntities()
{
	this->m_display.entityDisplay(this->m_player);
}