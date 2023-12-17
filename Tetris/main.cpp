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
        
        // FOR DRAWING SQUARE
        for (int row = 0; row < numRows; row++)
        {
            for (int column = 0; column < numCols; column++)
            {
                int cellValue = board[row][column];
                sf::RectangleShape square;
                sf::Vector2f position(column * cellSize + 1, row * cellSize + 1);
                square.setPosition(position);
                square.setSize(sf::Vector2f(cellSize - 1, cellSize - 1));
                square.setFillColor(colors[cellValue]);

            }
        }
        window.draw(board.Draw());
    
        window.display();

    }

    return 0;
}