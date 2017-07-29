#include "Movable.h"



Movable::Movable()
{
	this->m_id = 0;
	this->m_name = "UNAMED MOVABLE";
	this->m_pos.posX = 0;
	this->m_pos.posY = 0;
	this->m_speed = 1;
	this->m_lastAction = 0;
	this->m_type = unknowEntity;
}
/*
Movable::Movable(int id, std::string name, int posX, int posY, int speed)
{
	this->m_id = id;
	this->m_name = name;
	this->m_pos.posX = posX;
	this->m_pos.posY = posY;
	this->m_speed = speed;
	this->m_lastAction = 0;
	this->m_type = unknowEntity;
}
*/

Movable::Movable(int id, std::string name, Position pos, int speed)
{
	this->m_id = id;
	this->m_name = name;
	this->m_pos = pos;
	this->m_speed = speed;
	this->m_lastAction = 0;
	this->m_type = unknowEntity;
}

Movable::~Movable()
{
}

void Movable::moveRight()
{	
	//if (clock() - this->m_lastAction > (float)(this->m_speed * 100.f))
	{
		this->m_pos.posX++;
		//this->m_lastAction = clock();
	}
}

void Movable::moveLeft()
{
	//if (clock() - this->m_lastAction > (float)(this->m_speed * 100.f))
	{
		this->m_pos.posX--;
		//this->m_lastAction = clock();
	}
}

void Movable::moveUp()
{
	//if (clock() - this->m_lastAction > (float)(this->m_speed * 100.f))
	{
		this->m_pos.posY--;
		//this->m_lastAction = clock();
	}
}

void Movable::moveDown()
{
	//if (clock() - this->m_lastAction > (float)(this->m_speed * 100.f))
	{
		this->m_pos.posY++;
		//this->m_lastAction = clock();
	}
}

void Movable::moveUpRight()
{
	//if (clock() - this->m_lastAction > (float)(this->m_speed * 100.f))
	{
		this->m_pos.posY--;
		this->m_pos.posX++;
		//this->m_lastAction = clock();
	}
}

void Movable::moveUpLeft()
{
	//if (clock() - this->m_lastAction > (float)(this->m_speed * 100.f))
	{
		this->m_pos.posY--;
		this->m_pos.posX--;
		//this->m_lastAction = clock();
	}
}

void Movable::moveDownRight()
{
	//if (clock() - this->m_lastAction > (float)(this->m_speed * 100.f))
	{
		this->m_pos.posY++;
		this->m_pos.posX++;
		//this->m_lastAction = clock();
	}
}

void Movable::moveDownLeft()
{
	//if (clock() - this->m_lastAction > (float)(this->m_speed * 100.f))
	{
		this->m_pos.posY++;
		this->m_pos.posX--;
		//this->m_lastAction = clock();
	}
}

void Movable::move(std::string mouvement)
{
	if (mouvement == "right")
	{
		this->moveRight();
	}
	else if (mouvement == "left")
	{
		this->moveLeft();
	}
	else if (mouvement == "up")
	{
		this->moveUp();
	}
	else if (mouvement == "down")
	{
		this->moveDown();
	}
	else if (mouvement == "upRight")
	{
		this->moveUpRight();
	}
	else if (mouvement == "upLeft")
	{
		this->moveUpLeft();
	}
	else if (mouvement == "downRight")
	{
		this->moveDownRight();
	}
	else if (mouvement == "downLeft")
	{
		this->moveDownLeft();
	}
}
/*
void Movable::setPosition(int x, int y)
{
	this->m_pos.posX = x;
	this->m_pos.posY = y;
}
*/
void Movable::setPosition(Position pos)
{
	this->m_pos = pos;
}