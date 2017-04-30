#include "Ennemi.h"

Ennemi::Ennemi()
{
	this->m_id = 0;
	this->m_name = "UNAMED ENNEMI";
	this->m_posX = 0;
	this->m_posX = 0;
	this->m_speed = 1;
	this->m_lastAction = 0;
	this->m_type = unknowEntity;
}

Ennemi::Ennemi(int id, std::string name, int posX, int posY, int speed)
{
	this->m_id = id;
	this->m_name = name;
	this->m_posX = posX;
	this->m_posY = posY;
	this->m_speed = speed;
	this->m_lastAction = 0;
	this->m_type = ennemi;
	this->m_state = inactif;
}

Ennemi::Ennemi(int id, int posX, int posY, monsterType type)
{
	switch (type)
	{
		case skeleton:
			this->m_id = id;
			this->m_name = "Skeleton";
			this->m_posX = posX;
			this->m_posY = posY;
			this->m_speed = 1;
			this->m_lastAction = 0;
			this->m_type = ennemi;
			this->m_state = patrol;
			this->m_health = 50;
			break;
	}

}

Ennemi::Ennemi(int id, int posX, int posY, monsterType type, ennemiState state, Position objectif)
{
	switch (type)
	{
	case skeleton:
		this->m_id = id;
		this->m_name = "Skeleton";
		this->m_posX = posX;
		this->m_posY = posY;
		this->m_speed = 1;
		this->m_lastAction = 0;
		this->m_type = ennemi;		
		this->m_health = 50;
		break;
	}
	switch (state)
	{
	case patrol:
		this->m_state = patrol;
		this->m_objectif;
		this->m_posInitial.posX = posX;
		this->m_posInitial.posY = posY;
		this->m_objectif = objectif;
		break;
	}

	this->m_previousPosition = this->m_posInitial;
}

Ennemi::~Ennemi()
{

}

ennemiState Ennemi::getState()
{
	return this->m_state;
}

void Ennemi::setState(ennemiState newState)
{
	this->m_state = newState;
}

void Ennemi::takeDamage(int damage)
{
	this->m_health -= damage;
}

void Ennemi::update()
{
	
}

bool Ennemi::isAlive()
{
	if (this->m_health > 0)
		return true;
	else
		return false;
}

Position Ennemi::getObjectif()
{
	return this->m_objectif;
}


Position Ennemi::getPreviousPosition()
{
	return this->m_previousPosition;
}

void Ennemi::setObjectif(Position newObjectif)
{
	this->m_objectif = newObjectif;
}

void Ennemi::setPreviousPosition(Position newPosition)
{
	this->m_previousPosition = newPosition;
}