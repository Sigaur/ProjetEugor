#include "Display.h"

Display::Display()
{
	std::cout << "SpritesDb Init" << std::endl;
	if (!this->textUnknow.loadFromFile("32x32.png", sf::IntRect(64, 0, 32, 32)))
	{
		std::cout << "ERROR" << std::endl;
	}
	if (!this->textBrickFloor.loadFromFile("32x32.png", sf::IntRect(32, 736, 32, 32)))
	{
		std::cout << "ERROR" << std::endl;
	}
	if (!this->textDoor_closed.loadFromFile("32x32.png", sf::IntRect(96, 704, 32, 32)))
	{
		std::cout << "ERROR" << std::endl;
	}
	if (!this->textDoor_open.loadFromFile("32x32.png", sf::IntRect(192, 704, 32, 32)))
	{
		std::cout << "ERROR" << std::endl;
	}
	if (!this->textStairsDown.loadFromFile("32x32.png", sf::IntRect(482, 704, 32, 32)))
	{
		std::cout << "ERROR" << std::endl;
	}
	if (!this->textStairsUp.loadFromFile("32x32.png", sf::IntRect(384, 704, 32, 32)))
	{
		std::cout << "ERROR" << std::endl;
	}
}

void Display::tileDisplay(Tile tile)
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
	sf::Sprite sprite;
	sprite.setPosition((float)(tile.getX() * 32.f), (float)(tile.getY() * 32.f));

	sf::CircleShape shape(16.f);
	shape.setPosition((float)(tile.getX() * 32.f), (float)(tile.getY() * 32.f));
	switch (tile.getType())
	{
	default:
		sprite.setTexture(this->textUnknow);
		break;
	case unknow:
		sprite.setTexture(this->textUnknow);
		break;
	case brickFloor:
		sprite.setTexture(this->textBrickFloor);
		break;
	case door_closed:
		sprite.setTexture(this->textDoor_closed);
		break;
	case door_open:
		sprite.setTexture(this->textDoor_open);
		break;
	case stairsDown:
		sprite.setTexture(this->textStairsDown);
		break;
	case stairsUp:
		sprite.setTexture(this->textStairsUp);
		break;
	}
	window.draw(sprite);
}

void Display::entityDisplay(Entity entity)
{	
	sf::CircleShape shape(5.f);
	shape.setPosition((float)(entity.getPosX() * 10.f), (float)(entity.getPosY() * 10.f));
	shape.setFillColor(sf::Color::Green);
	window.draw(shape);
}

void Display::entityDisplay(Movable entity)
{
	sf::CircleShape shape(5.f);
	shape.setPosition((float)(entity.getPosX() * 10.f), (float)(entity.getPosY() * 10.f));
	shape.setFillColor(sf::Color::Green);
	window.draw(shape);
}

