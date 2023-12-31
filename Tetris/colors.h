#pragma once
#include <SFML/Graphics.hpp>
#include "LList.h"

extern const sf::Color grey;
extern const sf::Color green;
extern const sf::Color red;
extern const sf::Color orange;
extern const sf::Color yellow;
extern const sf::Color purple;
extern const sf::Color cyan;
extern const sf::Color blue;
extern const sf::Color darkBlue;




//LList<sf::Color> GetCellColors();
sf::Color* GetCellColors();