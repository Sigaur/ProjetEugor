#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#define WINDOWX 800
#define WINDOWY 800
#define VIEWPORTX 1600
#define VIEWPORTY 1600

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
typedef struct Position
{
	int posX;
	int posY;
};