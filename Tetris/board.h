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


	//LList<sf::Color> Colors;
	
	//Vector<sf::Color> Colors;
	//std::vector<sf::Color> colors;
	

private:
	int numRows;
	int numCols;
	int cellSize;
	//sf::Color* colors = new sf::Color[100];
	sf::Color* colors = new sf::Color[100];
	//std::vector<sf::Color> colors;
	//LList<sf::Color> colors;

};