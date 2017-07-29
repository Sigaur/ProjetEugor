#include "Entity.h"


Entity::Entity()
{
	this->m_id = 0;
	this->m_name = "UNAMED ENTITY";
	this->m_pos.posX = 0;
	this->m_pos.posY = 0;

	this->m_view = 5;
	this->m_type = unknowEntity;
}
/*
Entity::Entity(int id, std::string name, int posX, int posY)
{
	this->m_id = id;
	this->m_name = name;
	this->m_pos.posX = posX;
	this->m_pos.posY = posY;
}
*/

Entity::Entity(int id, std::string name, Position pos)
{
	this->m_id = id;
	this->m_name = name;
	this->m_pos = pos;
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
	return this->m_pos.posX;
}

int Entity::getPosY()
{
	return this->m_pos.posY;
}

Position Entity::getPosition()
{
	return this->m_pos;
}

void Entity::setView(int view)
{
	this->m_view = view;
}

int Entity::getView()
{
	return this->m_view;
}
/*
void Entity::setPos(int x, int y)
{
	this->m_pos.posX = x;
	this->m_pos.posY = y;
}
*/
void Entity::setPos(Position pos)
{
	this->m_pos = pos;
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