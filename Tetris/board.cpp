#include "board.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Board::Board() 
{
	numRows = 20;
	numCols = 10;
	cellSize = 30;
	Init();
	GetCellColors();

}

// GETTERS
//int Board::getNumCols() 
//{
//	return numCols;
//}
//
//int Board::getNumRows()
//{
//	return numRows;
//}
//
//int Board::getCellSize() 
//{
//	return cellSize;
//}


void Board::Init() {
	for (int row = 0; row < numRows; row++) 
	{
		for (int column = 0; column < numCols; column++)
		{
			board[row][column] = 0;
		}
	
	}

}

void Board::Print()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int column = 0; column < numCols; column++)
		{
			std::cout << board[row][column] << " ";
		}
		std::cout << std::endl;

	}
}

void Board::GetCellColors() {

	sf::Color grey(26, 31, 40, 255);
	sf::Color green(47, 230, 23, 255);
	sf::Color red(232, 18, 18, 255);
	sf::Color orange(226, 116, 17, 255);
	sf::Color yellow(237, 234, 4, 255);
	sf::Color purple(166, 0, 247, 255);
	sf::Color cyan(21, 204, 209, 255);
	sf::Color blue(13, 64, 216, 255);
	colors[0] = grey;
	colors[1] = green;
	colors[2] = red;
	colors[3] = orange;
	colors[4] = yellow;
	colors[5] = purple;
	colors[6] = cyan;
	colors[7] = blue;

}

void Board::Draw() 
{
	for (int row = 0; row < numRows; row++) 
	{
		for (int column = 0; column < numCols; column++) 
		{
			int cellValue = board[row][column];
			sf::RectangleShape square;
			sf::Vector2f position(column * cellSize+1, row * cellSize+1);
			square.setPosition(position);
			square.setSize(sf::Vector2f(cellSize -1 ,cellSize-1));
			square.setFillColor(colors[cellValue]);
			
		}
	}
}