#pragma once
#include "Movable.h"

class Ennemi : public Movable
{
public:
	Ennemi();
	Ennemi(int id, std::string name, int posX, int posY, int speed);
	~Ennemi();

	ennemiState getState();

protected:
	ennemiState state;
};