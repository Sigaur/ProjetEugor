#pragma once
#include "Movable.h"

class Ennemi : public Movable
{
public:
	Ennemi();
	Ennemi(int id, std::string name, int posX, int posY, int speed);
	Ennemi(int id, int posX, int posY, monsterType type);
	~Ennemi();

	ennemiState getState();
	void setState(ennemiState newState);

	void takeDamage(int damage);
	void update();

	bool isAlive();

protected:
	ennemiState m_state;
	monsterType m_monsterType;

	int m_health;
};