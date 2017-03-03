#pragma once
#include "Carte.h"
#include "Ennemi.h"

class Display {
public:
	Display();
	void tileDisplay(Tile tile, bool fade);

	void entityDisplay(Entity entity);
	void entityDisplay(Movable entity);
	void entityDisplay(Ennemi ennemi);

	void displayLevel(int level);

private:
	sf::Texture text32x32;
	sf::Texture IHM_Left;
	sf::Texture IHM_Bottom;
	sf::Texture IHM_Right;

	//Tiles:
	sf::IntRect rectUnknow;
	sf::IntRect rectDeflt;
	sf::IntRect rectBrickFloor;
	sf::IntRect rectDoor_closed;
	sf::IntRect rectDoor_open;
	sf::IntRect rectStairsDown;
	sf::IntRect rectStairsUp;
	sf::IntRect rectEnnemi;
	sf::IntRect rectEmergium;

	//Entities:
	sf::IntRect rectPlayer;
	sf::IntRect rectEnnemiInactif;
	sf::IntRect rectEnnemiPatrol;
	sf::IntRect rectEnnemiDefence;
	sf::IntRect rectUnknowEntity;

	sf::Font font;
	sf::Text text;
};


