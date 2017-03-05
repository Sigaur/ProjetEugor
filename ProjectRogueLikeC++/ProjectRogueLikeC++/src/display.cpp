#include "Display.h"

Display::Display()
{
	//std::cout << "SpritesDb Init" << std::endl;
	//Tiles:
	this->rectUnknow = sf::IntRect(64, 0, TILE_SIZE, TILE_SIZE);
	this->rectDeflt = sf::IntRect(704, 736, TILE_SIZE, TILE_SIZE);
	this->rectBrickFloor = sf::IntRect(32, 736, TILE_SIZE, TILE_SIZE);
	this->rectDoor_closed = sf::IntRect(96, 704, TILE_SIZE, TILE_SIZE);
	this->rectDoor_open = sf::IntRect(192, 704, TILE_SIZE, TILE_SIZE);
	this->rectStairsDown = sf::IntRect(482, 704, TILE_SIZE, TILE_SIZE);
	this->rectStairsUp = sf::IntRect(384, 704, TILE_SIZE, TILE_SIZE);	
	this->rectEmergium = sf::IntRect(704, 768, TILE_SIZE, TILE_SIZE);

	//Entities
	this->rectPlayer = sf::IntRect(96, 448, TILE_SIZE, TILE_SIZE);
	this->rectEnnemiInactif = sf::IntRect(896, 640, TILE_SIZE, TILE_SIZE);
	this->rectEnnemiPatrol = sf::IntRect(1216, 640, TILE_SIZE, TILE_SIZE);
	this->rectEnnemiDefence = sf::IntRect(1344, 640, TILE_SIZE, TILE_SIZE);
	this->rectUnknowEntity = sf::IntRect(0, 800, TILE_SIZE, TILE_SIZE);

	if (!this->text32x32.loadFromFile("image/32x32.png", sf::IntRect(0, 0, 4096, 960)))
	{
		std::cout << "ERROR 32x32.png not found" << std::endl;
	}
	if (!this->IHM_Left.loadFromFile("image/IHM_Left.png", sf::IntRect(0, 0, 0.25*WINDOWX, WINDOWY)))
	{
		std::cout << "ERROR IHM_Left.png not found" << std::endl;
	}
	if (!this->IHM_Right.loadFromFile("image/IHM_Right.png", sf::IntRect(0, 0, 0.25*WINDOWX, WINDOWY)))
	{
		std::cout << "ERROR IHM_Right.png not found" << std::endl;
	}
	if (!this->IHM_Bottom.loadFromFile("image/IHM_Bottom.png", sf::IntRect(0, 0, 0.5*WINDOWX, 0.11*WINDOWY)))
	{
		std::cout << "ERROR IHM_Bottom.png not found" << std::endl;
	}
	if (!font.loadFromFile("font/DODG5.ttf"))
	{
		std::cout << "ERROR DODG5.ttf not found" << std::endl;
	}
}

void Display::tileDisplay(Tile tile, bool fade)
{
	sf::Sprite sprite;
	sprite.setPosition((float)(tile.getX() * TILE_SIZE), (float)(tile.getY() * TILE_SIZE));
	sprite.setTexture(this->text32x32);

	sf::CircleShape shape(16.f);
	shape.setPosition((float)(tile.getX() * TILE_SIZE), (float)(tile.getY() * TILE_SIZE));
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
	sprite.setPosition((float)(entity.getPosX() * TILE_SIZE), (float)(entity.getPosY() * TILE_SIZE));
	sprite.setTexture(this->text32x32);
	switch (entity.getType())
	{
	default:
		sprite.setTextureRect(this->rectUnknowEntity);
		break;
	case unknow:
		sprite.setTextureRect(this->rectUnknowEntity);
		break;
	case player:
		sprite.setTextureRect(this->rectPlayer);
		break;
	}
	window.draw(sprite);
	/*
	sf::CircleShape shape(5.f);
	shape.setPosition((float)(entity.getPosX() * 10.f), (float)(entity.getPosY() * 10.f));
	shape.setFillColor(sf::Color::Green);
	window.draw(shape);
	*/
}

void Display::entityDisplay(Ennemi ennemi)
{
	sf::Sprite sprite;
	sprite.setPosition((float)(ennemi.getPosX() * TILE_SIZE), (float)(ennemi.getPosY() * TILE_SIZE));
	sprite.setTexture(this->text32x32);
	switch (ennemi.getState())
	{
	default:
		sprite.setTextureRect(this->rectUnknowEntity);
		break;
	case inactif:
		sprite.setTextureRect(this->rectEnnemiInactif);
		break;
	case patrol:
		sprite.setTextureRect(this->rectEnnemiPatrol);
		break;
	case defence:
		sprite.setTextureRect(this->rectEnnemiDefence);
		break;
	case seek:
		sprite.setTextureRect(this->rectPlayer);
		break;
	}
	window.draw(sprite);
}

void Display::entityDisplay(Ennemi* ennemi)
{
	sf::Sprite sprite;
	sprite.setPosition((float)(ennemi->getPosX() * TILE_SIZE), (float)(ennemi->getPosY() * TILE_SIZE));
	sprite.setTexture(this->text32x32);
	switch (ennemi->getState())
	{
	default:
		sprite.setTextureRect(this->rectUnknowEntity);
		break;
	case inactif:
		sprite.setTextureRect(this->rectEnnemiInactif);
		break;
	case patrol:
		sprite.setTextureRect(this->rectEnnemiPatrol);
		break;
	case defence:
		sprite.setTextureRect(this->rectEnnemiDefence);
		break;
	case seek:
		sprite.setTextureRect(this->rectPlayer);
		break;
	}
	window.draw(sprite);
}

void Display::entityDisplay(Movable entity)
{
	sf::Sprite sprite;
	sprite.setPosition((float)(entity.getPosX() * TILE_SIZE), (float)(entity.getPosY() * TILE_SIZE));
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
	spriteIHM_Bottom.setPosition(0.25*WINDOWX, 0.89*WINDOWY);
	window.draw(spriteIHM_Bottom);

	sf::Sprite spriteIHM_Right;
	spriteIHM_Right.setTexture(this->IHM_Right);
	spriteIHM_Right.setPosition(0.75*WINDOWX, 0);
	window.draw(spriteIHM_Right);

	std::string temp = "Level : ";	
	temp += std::to_string(level);
	
	text.setFont(font);
	text.setPosition(15, 10);
	//text.setColor(sf::Color::Green);
	text.setString(temp);
	window.draw(text);
}