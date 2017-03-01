#pragma once
#include "Common.h"

#define TILE_SIZE 32

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
	void setWalkable(bool walk);
	void setSeeThr(bool seeThr);
	bool isSeeThr();
	void setType(tileType type);
	
	bool isFull();
	void fulling();
	void digging();

	void setExplored(bool explored);
	bool isExplored();

	int getX();
	int getY();
	tileType getType();
private:
	bool m_walkable;
	bool m_seeThr;
	bool m_explored;
	unsigned int m_x;
	unsigned int m_y;
	bool m_full;
	tileType m_type;
};

