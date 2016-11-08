#include "Display.h"

void tileDisplay(Tile tile)
{
	/*
	sf::CircleShape shape(5.f);
	shape.setPosition((float) (tile.getX() * 10.f), (float) (tile.getY() * 10.f));
	if (!tile.isWalkable())
	{
		shape.setFillColor(sf::Color::Red);
	}
	else
	{
		shape.setFillColor(sf::Color::White);
	}
	if (tile.getX() == 25 && tile.getY() == 25)
	{
		//shape.setFillColor(sf::Color::Green);
	}
	else if (tile.getId() == 3)
	{
		//shape.setFillColor(sf::Color::Yellow);
	}
	else if (tile.getId() == 4)
	{
		shape.setFillColor(sf::Color::Blue);
	}
	window.draw(shape);
	*/
	sf::CircleShape shape(5.f);
	shape.setPosition((float)(tile.getX() * 10.f), (float)(tile.getY() * 10.f));
	switch (tile.getType())
	{
	default:
		shape.setFillColor(sf::Color::Magenta);
		break;
	case unknow:
		shape.setFillColor(sf::Color::Black);
		break;
	case brickFloor:
		shape.setFillColor(sf::Color::White);
		break;
	case door_closed:
		shape.setFillColor(sf::Color::Red);
		break;
	case door_open:
		shape.setFillColor(sf::Color::Blue);
		break;
	case stairsDown:
		shape.setFillColor(sf::Color::Yellow);
		break;
	case stairsUp:
		shape.setFillColor(sf::Color::Cyan);
		break;
	}
	window.draw(shape);
}

void entityDisplay(Entity entity)
{	
	sf::CircleShape shape(5.f);
	shape.setPosition((float)(entity.getPosX() * 10.f), (float)(entity.getPosY() * 10.f));
	shape.setFillColor(sf::Color::Green);
	window.draw(shape);
}

void entityDisplay(Movable entity)
{
	sf::CircleShape shape(5.f);
	shape.setPosition((float)(entity.getPosX() * 10.f), (float)(entity.getPosY() * 10.f));
	shape.setFillColor(sf::Color::Green);
	window.draw(shape);
}

