#include "Tile.h"


Tile::Tile()
{
	this->m_walkable = 0;
	this->m_x = 0;
	this->m_y = 0;
	this->m_full = 1;
	this->m_type = unknow;
	this->m_explored = false;
}

Tile::Tile(int walk, int x, int y)
{
	this->m_walkable = walk;
	this->m_x = x;
	this->m_y = y;
	this->m_type = unknow;
}

Tile::~Tile()
{
}

bool Tile::walking()///MANAGING INTERACTIONS WITH NON MOVABLE OBJECTS
{
	if (this->m_type == door_closed)
	{
		this->openDoor();
		return 0;
	}
	else
	{
		return this->isWalkable();
	}
}

bool Tile::isWalkable()
{
	return this->m_walkable;
}

bool Tile::isSeeThr()
{
	return this->m_seeThr;
}

void Tile::openDoor()
{
	if (this->m_type == door_closed)
	{
		this->setType(door_open);
	}
}

void Tile::set(int walk, int x, int y)
{
	this->m_walkable = walk;
	this->m_x = x;
	this->m_y = y;
}

void Tile::setWalkable(bool walk)
{
	this->m_walkable = walk;
}

void Tile::setSeeThr(bool seeThr)
{
	this->m_seeThr = seeThr;
}

void Tile::setExplored(bool explored)
{
	this->m_explored = explored;
}

bool Tile::isExplored()
{
	return this->m_explored;
}

int Tile::getX()
{
	return this->m_x;
}

int Tile::getY()
{
	return this->m_y;
}

bool Tile::isFull()
{
	return this->m_full;
}

void Tile::fulling()
{
	this->m_full = 1;
	this->m_walkable = 0;
}

void Tile::digging()
{
	if (this->m_full = 0)
	{
		std::cout << "ERREUR" << std::endl;
	}
	this->m_full = 0;
	this->m_walkable = 1;
}

void Tile::setType(tileType type)
{
	this->m_type = type;
	switch (m_type)
	{
	case unknow:
		this->setWalkable(false);
		this->setSeeThr(false);
		break;
	case brickFloor:
		this->setWalkable(true);
		this->setSeeThr(true);
		break;
	case door_open:
		this->setWalkable(true);
		this->setSeeThr(true);
		break;
	case door_closed:
		this->setWalkable(false);
		this->setSeeThr(false);
		break;
	case stairsDown:
		this->setWalkable(true);
		this->setSeeThr(true);
		break;
	case stairsUp:
		this->setWalkable(true);
		this->setSeeThr(true);
		break;
	case emergium:
		this->setWalkable(true);
		this->setSeeThr(true);
		break;
	default:
		this->setWalkable(false);
		this->setSeeThr(false);
		break;
	}
}

tileType Tile::getType()
{
	return this->m_type;
}