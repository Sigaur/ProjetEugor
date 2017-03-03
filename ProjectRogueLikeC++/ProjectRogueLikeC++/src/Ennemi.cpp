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
	this->state = inactif;
}

Ennemi::~Ennemi()
{
}

ennemiState Ennemi::getState()
{
	return this->state;
}