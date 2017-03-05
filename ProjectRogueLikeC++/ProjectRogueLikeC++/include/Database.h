#pragma once

#include"Display.h"

class Database
{
public:
	Database();
	~Database();

	void displayAll();
	void displayAll(int x, int y);

	void createLevel(int seed);
	void displayCarte();
	void displayCarte(int initX, int initY);
	void FOV(int minX, int maxX, int minY, int maxY);
	void displayTile(int x, int y, bool fade);
	void displayTile(Position position, bool fade);

	void displayEntities();
	void updateEnnemies();

	bool getInteraction(int x1, int y1);//Launch the interaction with a ennemi for example and return if it can be walked
	
	Carte m_carte;
	Movable m_player;
	std::vector< Ennemi* > m_ennemis;
	Display m_display;

	std::vector< std::vector <bool> > m_doors;
	std::vector< std::vector< std::vector <bool> > > m_explored;

	std::vector<Position> m_visible;//All the postions visible by the player at the moment
	std::vector<Ennemi*> m_visibleEnnemies;

private:
};

