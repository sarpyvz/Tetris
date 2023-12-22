#include "colors.h"

const sf::Color grey(26, 31, 40, 255);
const sf::Color green(47, 230, 23, 255);
const sf::Color red(232, 18, 18, 255);
const sf::Color orange(226, 116, 17, 255);
const sf::Color yellow(237, 234, 4, 255);
const sf::Color purple(166, 0, 247, 255);
const sf::Color cyan(21, 204, 209, 255);
const sf::Color blue(13, 64, 216, 255);

sf::Color* GetCellColors()
{
	colors[0] = grey;
	colors[1] = green;
	colors[2] = red;
	colors[3] = orange;
	colors[4] = yellow;
	colors[5] = purple;
	colors[6] = cyan;
	colors[7] = blue;
	
	return colors;
}