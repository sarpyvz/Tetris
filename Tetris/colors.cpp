#include "colors.h"
#include <SFML/Graphics.hpp>

const sf::Color grey(26, 31, 40, 255);
const sf::Color green(47, 230, 23, 255);
const sf::Color red(232, 18, 18, 255);
const sf::Color orange(226, 116, 17, 255);
const sf::Color yellow(237, 234, 4, 255);
const sf::Color purple(166, 0, 247, 255);
const sf::Color cyan(21, 204, 209, 255);
const sf::Color blue(13, 64, 216, 255);


//LList<sf::Color> GetCellColors()
//{
//	LList<sf::Color> colors_;
//	
//	colors_.addToTail(grey);
//	colors_.addToTail(green);
//	colors_.addToTail(red);
//	colors_.addToTail(orange);
//	colors_.addToTail(yellow);
//	colors_.addToTail(purple);
//	colors_.addToTail(cyan);
//	colors_.addToTail(blue);
//
//
//	return colors_;
//}
//
sf::Color* GetCellColors() {
	sf::Color* colors_ = new sf::Color[100];
	colors_[0] = grey;
	colors_[1] = green;
	colors_[2] = red;
	colors_[3] = orange;
	colors_[4] = yellow;
	colors_[5] = purple;
	colors_[6] = cyan;
	colors_[7] = blue;

	return colors_;
}

//std::vector<sf::Color> GetCellColors()
//{
//	return { grey,green,red,orange,yellow,purple,cyan,blue };
//}