#pragma once
#include "common.h"

class Tile
{
public:
	Tile();
	Tile(int walk, int id, int x, int y);
	~Tile();
	bool isWalkable();	
	void set(int walk, int id, int x, int y);
	void set(int walk, int id);
	
	bool isFull();
	void fulling();
	void digging();

	int getX();
	int getY();
	int getId();
private:
	bool m_walkable;
	int m_id;
	int m_x;
	int m_y;
	bool m_full;
};

