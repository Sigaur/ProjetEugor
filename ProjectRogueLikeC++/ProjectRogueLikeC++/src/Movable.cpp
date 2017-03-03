#include "Movable.h"



Movable::Movable()
{
	this->m_id = 0;
	this->m_name = "UNAMED MOVABLE";
	this->m_posX = 0;
	this->m_posX = 0;
	this->m_speed = 1;
	this->m_lastAction = 0;
	this->m_type = unknowEntity;
}

Movable::Movable(int id, std::string name, int posX, int posY, int speed)
{
	this->m_id = id;
	this->m_name = name;
	this->m_posX = posX;
	this->m_posY = posY;
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
		this->m_posX++;
		//this->m_lastAction = clock();
	}
}

void Movable::moveLeft()
{
	//if (clock() - this->m_lastAction > (float)(this->m_speed * 100.f))
	{
		this->m_posX--;
		//this->m_lastAction = clock();
	}
}

void Movable::moveUp()
{
	//if (clock() - this->m_lastAction > (float)(this->m_speed * 100.f))
	{
		this->m_posY--;
		//this->m_lastAction = clock();
	}
}

void Movable::moveDown()
{
	//if (clock() - this->m_lastAction > (float)(this->m_speed * 100.f))
	{
		this->m_posY++;
		//this->m_lastAction = clock();
	}
}

void Movable::moveUpRight()
{
	//if (clock() - this->m_lastAction > (float)(this->m_speed * 100.f))
	{
		this->m_posY--;
		this->m_posX++;
		//this->m_lastAction = clock();
	}
}

void Movable::moveUpLeft()
{
	//if (clock() - this->m_lastAction > (float)(this->m_speed * 100.f))
	{
		this->m_posY--;
		this->m_posX--;
		//this->m_lastAction = clock();
	}
}

void Movable::moveDownRight()
{
	//if (clock() - this->m_lastAction > (float)(this->m_speed * 100.f))
	{
		this->m_posY++;
		this->m_posX++;
		//this->m_lastAction = clock();
	}
}

void Movable::moveDownLeft()
{
	//if (clock() - this->m_lastAction > (float)(this->m_speed * 100.f))
	{
		this->m_posY++;
		this->m_posX--;
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

void Movable::setPosition(int x, int y)
{
	m_posX = x;
	m_posY = y;
}