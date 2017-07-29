#pragma once
#include "Movable.h"

class Ennemi : public Movable
{
public:
	Ennemi();
	//Ennemi(int id, std::string name, int posX, int posY, int speed);
	Ennemi(int id, std::string name, Position pos, int speed);

	//Ennemi(int id, int posX, int posY, monsterType type);
	Ennemi(int id, Position pos, monsterType type);
	
	//Ennemi(int id, int posX, int posY, monsterType type, ennemiState state, Position objectif);
	Ennemi(int id, Position pos, monsterType type, ennemiState state, Position objectif);
	~Ennemi();

	
	void setState(ennemiState newState);

	void takeDamage(int damage);
	void update();

	bool isAlive();

	//Used for ennemiesMouvement of database
	ennemiState getState();
	Position getObjectif();
	Position getPreviousPosition();
	void setObjectif(Position newObjectif);
	void setPreviousPosition(Position newPosition);

protected:
	ennemiState m_state;
	monsterType m_monsterType;

	Position m_objectif;
	Position m_posInitial;
	Position m_previousPosition;

	int m_health;
};