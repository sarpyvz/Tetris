#pragma once

#include "LList.h"
#include <SFML/Graphics.hpp>

class Board {

public:
	Board();
	void Init();
	void Print();
	void Draw();
	int board[20][10];

	int getNumRows();
	int getNumCols();
	int getCellSize();


	sf::Color* colors = new sf::Color[100];
	int numRows;
	int numCols;
	int cellSize;

private:
	//int numRows;
	//int numCols;
	//int cellSize;
	//sf::Color* colors = new sf::Color[100];
	void GetCellColors();

};