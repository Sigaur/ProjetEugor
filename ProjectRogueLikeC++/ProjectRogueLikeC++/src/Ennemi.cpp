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

			break;
	}
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
	if (m_health <= 0)
	{
		delete this;
	}
}