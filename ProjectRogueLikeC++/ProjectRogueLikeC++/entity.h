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
	Position getPosition();
	void setPos(int x, int y);

	int getId();
	void setId(int id);
	std::string getName();
	void setName(std::string name);

	void setView(int view);
	int getView();

protected:
	int m_view;
	int m_id;
	std::string m_name;
	int m_posX;
	int m_posY;
};

