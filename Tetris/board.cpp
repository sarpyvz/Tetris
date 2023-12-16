#include "board.h"
#include <iostream>

Board::Board() 
{
	numRows = 20;
	numCols = 10;
	cellSize = 30;
	Init();
}

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