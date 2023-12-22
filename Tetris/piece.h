#pragma once
#include <map>
#include "position.h"
#include "Llist.h"
#include "colors.h"
#include <SFML/Graphics.hpp>

class Piece 
{
public:
	Piece();
	int id;
	std::map<int, LList<Position>> cells;
	void Draw(sf::RenderTarget& target);

	int cellSize;
	int rotationState;
	sf::Color* colors = new sf::Color;

};