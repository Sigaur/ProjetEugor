#include "Display.h"

Display::Display()
{
	//std::cout << "SpritesDb Init" << std::endl;
	
	this->rectUnknow = sf::IntRect(64, 0, 32, 32);
	this->rectDeflt = sf::IntRect(704, 736, 32, 32);
	this->rectBrickFloor = sf::IntRect(32, 736, 32, 32);
	this->rectDoor_closed = sf::IntRect(96, 704, 32, 32);
	this->rectDoor_open = sf::IntRect(192, 704, 32, 32);
	this->rectStairsDown = sf::IntRect(482, 704, 32, 32);
	this->rectStairsUp = sf::IntRect(384, 704, 32, 32);
	this->rectPlayer = sf::IntRect(96, 448, 32, 32);
	this->rectEnnemi = sf::IntRect(1280, 512, 32, 32);
	this->rectEmergium = sf::IntRect(704, 768, 32, 32);
	if (!this->text32x32.loadFromFile("32x32.png", sf::IntRect(0, 0, 4096, 960)))
	{
		std::cout << "ERROR 32x32.png not found" << std::endl;
	}
	if (!this->IHM_Left.loadFromFile("IHM_Left.png", sf::IntRect(0, 0, 400, 900)))
	{
		std::cout << "ERROR IHM_Left.png not found" << std::endl;
	}
	if (!this->IHM_Right.loadFromFile("IHM_Right.png", sf::IntRect(0, 0, 400, 900)))
	{
		std::cout << "ERROR IHM_Right.png not found" << std::endl;
	}
	if (!this->IHM_Bottom.loadFromFile("IHM_Bottom.png", sf::IntRect(0, 0, 800, 100)))
	{
		std::cout << "ERROR IHM_Bottom.png not found" << std::endl;
	}
	if (!font.loadFromFile("DODG5.ttf"))
	{
		std::cout << "ERROR DODG5.ttf not found" << std::endl;
	}
}

void Display::tileDisplay(Tile tile, bool fade)
{
	sf::Sprite sprite;
	sprite.setPosition((float)(tile.getX() * 32.f), (float)(tile.getY() * 32.f));
	sprite.setTexture(this->text32x32);

	sf::CircleShape shape(16.f);
	shape.setPosition((float)(tile.getX() * 32.f), (float)(tile.getY() * 32.f));
	switch (tile.getType())
	{
	default:
		sprite.setTextureRect(this->rectUnknow);
		break;
	case unknow:
		sprite.setTextureRect(this->rectDeflt);
		break;
	case brickFloor:
		sprite.setTextureRect(this->rectBrickFloor);
		break;
	case door_closed:
		sprite.setTextureRect(this->rectDoor_closed);
		break;
	case door_open:
		sprite.setTextureRect(this->rectDoor_open);
		break;
	case stairsDown:
		sprite.setTextureRect(this->rectStairsDown);
		break;
	case stairsUp:
		sprite.setTextureRect(this->rectStairsUp);
		break;
	////////////Ores
	case emergium:
		sprite.setTextureRect(this->rectEmergium);
		break;
	}
	if(fade)
		sprite.setColor(sf::Color(255, 255, 255, 100));//Fade out for already explored ground

	window.draw(sprite);
}

void Display::entityDisplay(Entity entity)
{	
	sf::Sprite sprite;
	sprite.setPosition((float)(entity.getPosX() * 32.f), (float)(entity.getPosY() * 32.f));
	sprite.setTexture(this->text32x32);
	sprite.setTextureRect(this->rectPlayer);
	window.draw(sprite);
	/*
	sf::CircleShape shape(5.f);
	shape.setPosition((float)(entity.getPosX() * 10.f), (float)(entity.getPosY() * 10.f));
	shape.setFillColor(sf::Color::Green);
	window.draw(shape);
	*/
}

void Display::entityDisplay(Movable entity)
{
	sf::Sprite sprite;
	sprite.setPosition((float)(entity.getPosX() * 32.f), (float)(entity.getPosY() * 32.f));
	sprite.setTexture(this->text32x32);
	sprite.setTextureRect(this->rectPlayer);
	window.draw(sprite);
}

void Display::displayLevel(int level)
{
	///////Temporaire
	sf::Sprite spriteIHM_Left;
	spriteIHM_Left.setTexture(this->IHM_Left);
	window.draw(spriteIHM_Left);

	sf::Sprite spriteIHM_Bottom;
	spriteIHM_Bottom.setTexture(this->IHM_Bottom);
	spriteIHM_Bottom.setPosition(400, 800);
	window.draw(spriteIHM_Bottom);

	sf::Sprite spriteIHM_Right;
	spriteIHM_Right.setTexture(this->IHM_Right);
	spriteIHM_Right.setPosition(1200, 0);
	window.draw(spriteIHM_Right);

	std::string temp = "Level : ";	
	temp += std::to_string(level);
	
	text.setFont(font);
	//text.setColor(sf::Color::Green);
	text.setString(temp);
	window.draw(text);
}