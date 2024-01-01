#include "piece.h"
#include <SFML/Graphics.hpp>


Piece::Piece()
{
	cellSize = 30;
	rotationState = 0;
	colors = GetCellColors();
	rowOffset = 0;
	columnOffset = 0;

}

void Piece::Draw(sf::RenderWindow& target, int X_cor,int Y_cor)
{
	std::vector<Position> tiles = GetCellPositions();
	//Vector<Position> tiles = GetCellPositions();

	//for(int i = 0; i < 4;i++)
	for (Position item : tiles)
	{
		//Position item = tiles[i];
		sf::RectangleShape shape;
		sf::Vector2f position(item.column * cellSize + X_cor, item.row * cellSize + Y_cor);
		shape.setPosition(position);
		shape.setSize(sf::Vector2f(cellSize - 1, cellSize - 1));
		shape.setFillColor(colors[id]);
		target.draw(shape);
	}
}

void Piece::Move(int rows, int columns) 
{
	rowOffset += rows;
	columnOffset += columns;
}


std::vector<Position> Piece::GetCellPositions()
{
	std::vector<Position> tiles = cells[rotationState];
	std::vector<Position> movedTiles;
	for (Position item : tiles)
	{
		Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
		movedTiles.push_back(newPos);
	}
	return movedTiles;
}

// MY VECTOR IMPLEMENT
//Vector<Position> Piece::GetCellPositions()
//{
//	Vector<Position> tiles = cells[rotationState];
//	Vector<Position> movedTiles;
//	for (int i = 0; i < tiles.size(); i++) 
//	{
//		Position item = tiles[i];
//		Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
//		movedTiles.push_back(newPos);
//	}
//	return movedTiles;
//}


void Piece::Rotate()
{
	rotationState++;
	if (rotationState == cells.size())
	{
		rotationState = 0;
	}
}

void Piece::UndoRotation()
{
	rotationState--;
	if (rotationState == -1) 
	{
		rotationState = cells.size() - 1;
	}
}
