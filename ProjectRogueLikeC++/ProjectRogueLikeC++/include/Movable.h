#pragma once
#include "Entity.h"
#include <time.h>

class Movable : public Entity
{
public:
	Movable();
	//Movable(int id, std::string name, int posX, int posY, int speed);
	Movable(int id, std::string name, Position pos, int speed);
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

	//void setPosition(int x, int y);
	void setPosition(Position pos);
protected:
	float m_speed;
	int m_lastAction;
};

