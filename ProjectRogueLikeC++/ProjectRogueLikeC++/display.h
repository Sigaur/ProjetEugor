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
	sf::Texture textUnknow;
	sf::Texture textBrickFloor;	
	sf::Texture textDoor_closed;
	sf::Texture textDoor_open;
	sf::Texture textStairsDown;
	sf::Texture textStairsUp;
};


