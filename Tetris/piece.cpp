#include "piece.h"
#include <iostream>


Piece::Piece()
{
	cellSize = 30;
	rotationState = 0;
	colors = GetCellColors();

}

void Piece::Draw(sf::RenderTarget& target)
{
	LList<Position> tiles;
	for (int i = 0; i < 4; i++) { tiles.addToTail(cells[rotationState].GetAt(i)); }

	for (Position item : tiles)
	{
		sf::RectangleShape shape;
		sf::Vector2f position(item.column * cellSize + 1, item.row * cellSize + 1);
		shape.setPosition(position);
		shape.setSize(sf::Vector2f(cellSize - 1, cellSize - 1));
		shape.setFillColor(colors[id]);
		target.draw(shape);

	}
}