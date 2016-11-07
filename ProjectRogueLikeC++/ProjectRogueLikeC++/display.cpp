#include "display.h"

void tileDisplay(Tile tile)
{
	sf::CircleShape shape(5.f);
	shape.setPosition((float) (tile.getX() * 10.f), (float) (tile.getY() * 10.f));
	if (tile.isFull())
	{
		shape.setFillColor(sf::Color::Red);
	}
	else
	{
		shape.setFillColor(sf::Color::White);
	}
	if (tile.getX() == 50 && tile.getY() == 50)
	{
		shape.setFillColor(sf::Color::Green);
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
}
