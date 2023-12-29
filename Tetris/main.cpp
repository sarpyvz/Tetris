#include <SFML/Graphics.hpp>
#include "board.h"
#include "pieces.cpp"
#include "game.h"

double lastUpdateTime = 0;

static bool EventTriggered(double interval,sf::Clock clock)
{
    sf::Time totalTime = clock.getElapsedTime();
    double currenTime = totalTime.asSeconds();

    if (currenTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currenTime;
        return true;
    }
    
    return false;

}
int main()
{
    sf::RenderWindow window(sf::VideoMode(300, 600), "Tetris!");
    window.setFramerateLimit(60);
    sf::Clock clock;

    Game game = Game();


    while (window.isOpen())
    {
   

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        } 

        
        if (event.type == sf::Event::KeyPressed)
        {
            game.HandleInput(event.key.code);
        }
        if (EventTriggered(0.2,clock))
        {
            game.MovePieceDown();
        }
      
        window.clear(sf::Color::Black);

        game.Draw(window);
        window.display();
    }

    return 0;
}