#pragma once
#include "Entity.h"
#include <time.h>

class Movable : public Entity
{
public:
	Movable();
	Movable(int id, std::string name, int posX, int posY, int speed);
	~Movable();

	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
	void moveUpRight();
	void moveUpLeft();
	void moveDownRight();
	void moveDownLeft();
	void move(std::string mouvement);
protected:
	float m_speed;
	int m_lastAction;
};

