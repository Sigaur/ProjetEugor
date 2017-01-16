#pragma once
#include <vector>
#include "Tile.h"

class Carte {
public:
	Carte();
	~Carte();
	void setTest();

	//doorsGestion
	void setDoors(std::vector<bool> doors);
	std::vector<bool> saveDoors();

	//explored Gestion
	void setExplored(std::vector< std::vector<bool> > explored);
	std::vector< std::vector<bool> > saveExplored();

	void fulling(int x1, int y1, int x2, int y2);
	void digging(int x1, int y1, int x2, int y2, tileType type);
	bool isFull(int x1, int y1, int x2, int y2);
	bool isWalkable(int x1, int y1);
	bool isSeeThr(int x1, int y1);
	bool walking(int x1, int y1);
	void getInteraction(int x1, int y1);
	tileType getType(int x1, int y1);
	bool inBound(int x1, int y1, int x2, int y2);
	bool inBound(int x1, int y1);
	void pushingBack(std::vector<Tile> &vec, Tile tile);
	void swapping(int &x1, int &x2);
	std::string Carte::roomTypeGenerator(int &x1, int &y1, int &x2, int &y2, std::string from);

	void roomTest(int paraX, int paraY, int corrX, int corrY, std::string from);
	void corridorTest(int paraX, int paraY, int corrX, int corrY, bool vertical);
	Position Carte::getRandomFreeSpace();
	Position Carte::getPositionFromType(tileType type);
	void dungeonTest(int level);

	std::vector<std::vector<Tile>> m_matrix;

	Tile getTile(int x, int y);

	int getNoCols();
	int getNoRows();
	void setSize(int cols, int rows);
private:
	int no_of_cols;
	int no_of_rows;
	std::vector<Tile> wallConstructible;
	std::vector<Position> m_doors;
};
	


