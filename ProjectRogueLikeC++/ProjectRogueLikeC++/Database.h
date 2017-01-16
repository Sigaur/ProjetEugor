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
	void FOV(int minX, int maxX, int minY, int maxY);
	void displayTile(int x, int y, bool fade);
	void displayTile(Position position, bool fade);

	void displayEntities();
	
	Carte m_carte;
	Movable m_player;
	Display m_display;

	std::vector<std::vector <bool>> m_doors;

	std::vector<Position> m_visible;//All the postions visible by the player at the moment

private:
};

