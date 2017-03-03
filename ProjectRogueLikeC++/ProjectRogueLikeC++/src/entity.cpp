#include "Entity.h"


Entity::Entity()
{
	this->m_id = 0;
	this->m_name = "UNAMED ENTITY";
	this->m_posX = 0;
	this->m_posX = 0;

	this->m_view = 5;
	this->m_type = unknowEntity;
}

Entity::Entity(int id, std::string name, int posX, int posY)
{
	this->m_id = id;
	this->m_name = name;
	this->m_posX = posX;
	this->m_posY = posY;
}

Entity::~Entity()
{

}

entitiesType Entity::getType()
{
	return this->m_type;
}

int Entity::getPosX()
{
	return this->m_posX;
}

int Entity::getPosY()
{
	return this->m_posY;
}

Position Entity::getPosition()
{
	Position tempPosition;
	tempPosition.posX = this->m_posX;
	tempPosition.posY = this->m_posY;

	return tempPosition;
}

void Entity::setView(int view)
{
	this->m_view = view;
}

int Entity::getView()
{
	return this->m_view;
}

void Entity::setPos(int x, int y)
{
	this->m_posX = x;
	this->m_posY = y;
}

int Entity::getId()
{
	return this->m_id;
}

void Entity::setId(int id)
{
	this->m_id = id;
}

std::string Entity::getName()
{
	return this->m_name;
}

void Entity::setName(std::string name)
{
	this->m_name = name;
}