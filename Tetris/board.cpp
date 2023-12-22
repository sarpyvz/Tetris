#include "board.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "colors.h"

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

void Board::Print() const
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


void Board::Draw(sf::RenderWindow& target) 
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
			target.draw(square);
		}
	}
}