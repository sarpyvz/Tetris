#pragma once
#include <map>
#include "position.h"
#include "Llist.h"
#include "colors.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Piece 
{
public:
	Piece();
	int id;
	//std::map<int, LList<Position>> cells;
	std::map<int, std::vector<Position>> cells;
	//std::map<int, Vector<Position>>cells;

	void Draw(sf::RenderWindow& target,int X_cor,int Y_cor);
	std::vector<Position> GetCellPositions();
	//Vector<Position> GetCellPositions();
	void Move(int rows, int columns);
	void Rotate();
	void UndoRotation();

private:
	int cellSize;
	int rotationState;
	sf::Color* colors = new sf::Color[100];
	int rowOffset;
	int columnOffset;

};