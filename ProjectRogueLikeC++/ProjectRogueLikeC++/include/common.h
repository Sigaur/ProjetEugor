#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#define WINDOWX 1600
#define WINDOWY 900

#define MAPX 800
#define MAPY 800

#define NB_TILES_DISPLAY 12//number of tiles displayed around the player

extern sf::RenderWindow window;
enum tileType
{
	unknow,
	brickFloor,
	door_closed,
	door_open,
	stairsDown,
	stairsUp,
	////Ores
	emergium
};
enum entitiesType
{
	unknowEntity,
	player,
	ennemi
};
enum ennemiState
{
	inactif,
	patrol,
	defence,
	seek
};
typedef struct Position
{
	int posX;
	int posY;
};