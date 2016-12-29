#pragma once

#include"Display.h"

class Database
{
public:
	Database();
	~Database();

	void displayAll();

	void createLevel(int seed);
	void displayCarte();
	void displayTile(int x, int y);

	void displayEntities();
	
	Carte m_carte;
	Movable m_player;
	Display m_display;

	std::vector<std::vector <bool>> m_doors;

private:
};

