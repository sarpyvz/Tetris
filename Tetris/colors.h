#pragma once
#include <SFML/Graphics.hpp>
#include "LList.h"
#include <vector>

extern const sf::Color grey;
extern const sf::Color green;
extern const sf::Color red;
extern const sf::Color orange;
extern const sf::Color yellow;
extern const sf::Color purple;
extern const sf::Color cyan;
extern const sf::Color blue;




//std::vector<sf::Color> GetCellColors();
//LList<sf::Color> GetCellColors();
sf::Color* GetCellColors();
