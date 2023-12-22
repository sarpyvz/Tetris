#pragma once
#include <SFML/Graphics.hpp>

extern const sf::Color grey;
extern const sf::Color green;
extern const sf::Color red;
extern const sf::Color orange;
extern const sf::Color yellow;
extern const sf::Color purple;
extern const sf::Color cyan;
extern const sf::Color blue;
sf::Color* colors = new sf::Color[100];

sf::Color* GetCellColors();