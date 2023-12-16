#include <SFML/Graphics.hpp>
#include "board.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(300, 600), "Tetris!");
    window.setFramerateLimit(60);

    Board board = Board();
    board.Print();

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();

        } 

        window.clear(sf::Color::Black);

        window.display();

    }

    return 0;
}