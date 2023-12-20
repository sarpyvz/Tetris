#include <SFML/Graphics.hpp>
#include "board.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(300, 600), "Tetris!");
    window.setFramerateLimit(60);

    Board board = Board();
    board.board[0][0] = 1; // 0 DAN BAÞLIYOR 19 A VE 0 DAN 9 A  KADAR GÝDÝYOR O YÜZDEN 20 VEYA 10 YAZAMIYORUZ
    board.board[5][8] = 6;
    board.board[19][9] = 3;
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
        
        // FOR DRAWING GRID AND SQUARES
        
        for (int row = 0; row < board.numRows; row++)
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
        }


        window.display();

    }

    return 0;
}