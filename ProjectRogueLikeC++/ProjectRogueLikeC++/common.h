#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#define WINDOWX 500
#define WINDOWY 500

extern sf::RenderWindow window;
enum tileType
{
	unknow,
	brickFloor,
	door_closed,
	door_open,
	stairsDown,
	stairsUp
};
typedef struct Position
{
	int posX;
	int posY;
};