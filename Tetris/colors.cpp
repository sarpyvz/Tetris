#include "colors.h"
#include <SFML/Graphics.hpp>

const sf::Color grey(26, 31, 40, 255);
const sf::Color green(50, 205, 50, 255);
const sf::Color red(232, 18, 18, 255);
const sf::Color orange(255 ,127 ,36, 255);
const sf::Color yellow(255, 228, 19, 255);
const sf::Color purple(160, 32, 240, 255);
const sf::Color cyan(0, 191, 255,255);
const sf::Color blue(0 ,0 ,139, 255);
const sf::Color darkBlue(44, 44, 127, 255);
const sf::Color ghost(73, 73, 85);

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
	colors_[8] = ghost;

	return colors_;
}

