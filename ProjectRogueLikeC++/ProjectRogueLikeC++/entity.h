#pragma once
#include "Common.h"

class Entity
{
public:
	Entity();
	Entity(int id, std::string name, int posX, int posY);
	~Entity();

	int getPosX();
	int getPosY();
	void setPos(int x, int y);
	int getId();
	void setId(int id);
	std::string getName();
	void setName(std::string name);

protected:
	int m_id;
	std::string m_name;
	int m_posX;
	int m_posY;
};

