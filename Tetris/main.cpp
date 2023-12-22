#include <SFML/Graphics.hpp>
#include "board.h"
#include "pieces.cpp"


int main()
{
    sf::RenderWindow window(sf::VideoMode(300, 600), "Tetris!");
    window.setFramerateLimit(60);

    Board board = Board();
    board.Print();
    
    LPiece piece = LPiece();

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        } 

        window.clear(sf::Color::Black);
        
        // FOR DRAWING GRID AND SQUARES
        
        /*for (int row = 0; row < board.numRows; row++)
        {
            for (int column = 0; column < board.numCols; column++)
            {
                int cellValue = board.board[row][column];
                sf::RectangleShape square;
                sf::Vector2f position(column * board.cellSize + 1, row * board.cellSize + 1);
                square.setPosition(position);
                square.setSize(sf::Vector2f(board.cellSize - 1, board.cellSize - 1));
                square.setFillColor(board.colors[cellValue]);
                window.draw(square);
            }
        }*/

        board.Draw(window);
        piece.Draw(window);
       
        window.display();

    }

    return 0;
}