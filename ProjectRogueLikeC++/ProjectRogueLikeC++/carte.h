#pragma once
#include <vector>
#include "tile.h"
#include "display.h"

class Carte {
public:
	Carte();
	~Carte();
	void displayCarte();
	void setTest();

	void fulling(int x1, int y1, int x2, int y2);
	void digging(int x1, int y1, int x2, int y2);
	bool isFull(int x1, int y1, int x2, int y2);
	bool inBound(int x1, int y1, int x2, int y2);
	bool inBound(int x1, int y1);
	void pushingBack(std::vector<Tile> &vec, Tile tile);
	void swapping(int &x1, int &x2);

	void roomTest(int paraX, int paraY, int corrX, int corrY);
	void corridorTest(int paraX, int paraY, int corrX, int corrY, bool vertical);
	void dungeonTest();
private:
	std::vector<std::vector<Tile>> m_matrix;
	int no_of_cols;
	int no_of_rows;
	std::vector<Tile> wallConstructible;
};
	


