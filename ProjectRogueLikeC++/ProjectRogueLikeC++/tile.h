#pragma once
#include "Common.h"

class Tile
{
public:
	Tile();
	Tile(int walk, int x, int y);
	~Tile();
	bool walking();
	bool isWalkable();
	void openDoor();
	void set(int walk, int x, int y);
	void set(int walk);
	void setType(tileType type);
	
	bool isFull();
	void fulling();
	void digging();

	int getX();
	int getY();
	tileType getType();
private:
	bool m_walkable;
	int m_x;
	int m_y;
	bool m_full;
	tileType m_type;
};

