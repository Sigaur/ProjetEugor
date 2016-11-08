#include "Tile.h"


Tile::Tile()
{
	this->m_walkable = 0;
	this->m_id = 0;
	this->m_x = 0;
	this->m_y = 0;
	this->m_full = 1;
	this->m_type = unknow;
}

Tile::Tile(int walk, int id, int x, int y)
{
	this->m_walkable = walk;
	this->m_id = id;
	this->m_x = x;
	this->m_y = y;
	this->m_type = unknow;
}

Tile::~Tile()
{
}

bool Tile::isWalkable()
{
	return this->m_walkable;
}

void Tile::set(int walk, int id, int x, int y)
{
	this->m_walkable = walk;
	this->m_id = id;
	this->m_x = x;
	this->m_y = y;
}

void Tile::set(int walk, int id)
{
	this->m_walkable = walk;
	this->m_id = id;
}

int Tile::getX()
{
	return this->m_x;
}

int Tile::getY()
{
	return this->m_y;
}

int Tile::getId()
{
	return this->m_id;
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
}

tileType Tile::getType()
{
	return this->m_type;
}