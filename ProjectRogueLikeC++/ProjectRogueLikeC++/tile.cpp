#include "Tile.h"


Tile::Tile()
{
	this->m_walkable = 0;
	this->m_x = 0;
	this->m_y = 0;
	this->m_full = 1;
	this->m_type = unknow;
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

void Tile::set(int walk)
{
	this->m_walkable = walk;
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
		this->set(0);
		break;
	case brickFloor:
		this->set(1);
		break;
	case door_open:
		this->set(1);
		break;
	case stairsDown:
		this->set(1);
		break;
	case stairsUp:
		this->set(1);
		break;
	default:
		this->set(0);
		break;
	}
}

tileType Tile::getType()
{
	return this->m_type;
}