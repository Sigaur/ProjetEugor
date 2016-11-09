#pragma once
#include <vector>
#include "Tile.h"
#include "Display.h"

class Carte {
public:
	Carte();
	~Carte();
	void display(int x, int y);
	void displayCarte();	
	void setTest();

	//doorsGestion
	void displayDoors();
	void setDoors(std::vector<bool> doors);
	std::vector<bool> saveDoors();

	void fulling(int x1, int y1, int x2, int y2);
	void digging(int x1, int y1, int x2, int y2, tileType type);
	bool isFull(int x1, int y1, int x2, int y2);
	bool isWalkable(int x1, int y1);
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
private:
	std::vector<std::vector<Tile>> m_matrix;
	int no_of_cols;
	int no_of_rows;
	std::vector<Tile> wallConstructible;
	std::vector<Position> m_doors;
	int compteurDebug;
};
	


