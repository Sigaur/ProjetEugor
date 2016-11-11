#pragma once
#include "Tile.h"
#include "Common.h"
#include "Movable.h"

class Display {
public:
	Display();
	void tileDisplay(Tile tile);
	void entityDisplay(Entity entity);
	void entityDisplay(Movable entity);

private:
	sf::Texture text32x32;
	
	sf::IntRect rectUnknow;
	sf::IntRect rectBrickFloor;
	sf::IntRect rectDoor_closed;
	sf::IntRect rectDoor_open;
	sf::IntRect rectStairsDown;
	sf::IntRect rectStairsUp;
	sf::IntRect rectPlayer;
};


