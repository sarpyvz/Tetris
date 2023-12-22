#pragma once

#include "LList.h"
#include <SFML/Graphics.hpp>

class Board {

public:
	Board();
	void Init();
	void Print() const;
	void Draw(sf::RenderWindow& target);
	int board[20][10];



	sf::Color* colors = new sf::Color[100];
	int numRows;
	int numCols;
	int cellSize;

private:
	//int numRows;
	//int numCols;
	//int cellSize;
	//sf::Color* colors = new sf::Color[100];

};