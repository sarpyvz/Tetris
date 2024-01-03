#pragma once

#include "LList.h"
#include <SFML/Graphics.hpp>
#include "Vector.hpp"
#include <vector>

class Board {

public:
	Board();
	void Init();
	void Print() const;
	void Draw(sf::RenderWindow& target);
	int board[20][10];
	bool IsCellOutside(int row, int column);
	bool IsCellEmpty(int row, int column);
	int ClearFullRows();	

	//LList<sf::Color> Colors;
	
	//Vector<sf::Color> Colors;
	//std::vector<sf::Color> colors;
	void DecreaseNumRow(int n);


private:
	int numRows;
	int numCols;
	int cellSize;
	sf::Color* colors = new sf::Color[100];
	//std::vector<sf::Color> colors;
	//LList<sf::Color> colors;
	bool IsRowFull(int row);
	void ClearRow(int row);
	void MoveRowsDown(int row,int numRows);
};