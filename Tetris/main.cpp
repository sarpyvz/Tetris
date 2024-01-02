#include <SFML/Graphics.hpp>
#include "board.h"
#include "pieces.cpp"
#include "game.h"
#include "colors.h"
#include <SFML/Audio.hpp>

double lastUpdateTime = 0;

bool EventTriggered(double interval,sf::Clock clock)
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

sf::Vector2f measureText(const std::string& text, const sf::Font& font, unsigned int characterSize) {
    sf::Text sfmlText(text, font, characterSize);
    sf::FloatRect bounds = sfmlText.getLocalBounds();
    return sf::Vector2f(bounds.width, bounds.height);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(700, 620), "Tetris!");
    window.setFramerateLimit(60);
    sf::Clock clock;


    //----------FONT AND TEXT UI-----------------------------// 
    sf::Font font;
    font.loadFromFile("C:\\Users\\sarpy\\source\\repos\\Tetris\\font\\fast99.ttf");
    

    sf::Text score;
    score.setFont(font);
    score.setString("SCORE");
    score.setCharacterSize(20);
    score.setFillColor(sf::Color::White);
    sf::Vector2f position(365, 15);
    score.setPosition(position);
    
    sf::Text text_next;
    text_next.setFont(font);
    text_next.setString("NEXT");
    text_next.setCharacterSize(20);
    text_next.setFillColor(sf::Color::White);
    sf::Vector2f position2(370, 175);
    text_next.setPosition(position2);
  
    sf::Text text_gameover;
    text_gameover.setFont(font);
    text_gameover.setString("GAME OVER");
    text_gameover.setCharacterSize(20);
    text_gameover.setFillColor(sf::Color::White);
    sf::Vector2f position3(520, 570);
    text_gameover.setPosition(position3);

    sf::RectangleShape rectangle;
    sf::Vector2f position4(320,55);
    rectangle.setPosition(position4);
    rectangle.setSize(sf::Vector2f(170,60));
    rectangle.setFillColor(darkBlue);

    sf::RectangleShape rectangle_nxt;
    sf::Vector2f position5(320, 215);
    rectangle_nxt.setPosition(position5);
    rectangle_nxt.setSize(sf::Vector2f(170, 180));
    rectangle_nxt.setFillColor(darkBlue);

    sf::Text Hold_txt;
    Hold_txt.setFont(font);
    Hold_txt.setString("HOLD");
    Hold_txt.setCharacterSize(20);
    Hold_txt.setFillColor(sf::Color::White);
    sf::Vector2f position_hol(370, 415);
    Hold_txt.setPosition(position_hol);

    sf::RectangleShape rectangle_hold;
    sf::Vector2f position_hold(320, 450);
    rectangle_hold.setPosition(position_hold);
    rectangle_hold.setSize(sf::Vector2f(170, 150));
    rectangle_hold.setFillColor(darkBlue);
   
    //----------------------------------------------------------------//
    Game game = Game();

    while (window.isOpen())
    {
   
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                game.HandleInput(event.key.code,window);
                
            }
            
        } 

        
        if (EventTriggered(0.2, clock))
        {
            game.MovePieceDown();
        }
       
        window.clear(sf::Color::Black);

        if (game.gameover) 
        {
            window.draw(text_gameover);
        }

        window.draw(score);
        window.draw(text_next);
        window.draw(Hold_txt);
        window.draw(rectangle);

        /// --------- FOR SCORE VALUES --------- //
        
        std::string scoretxt = to_string(game.score);
        sf::Vector2f txtSize = measureText(scoretxt, font, 38);
        sf::Text scoretext;
        scoretext.setFont(font);
        scoretext.setString(scoretxt);
        scoretext.setCharacterSize(20);
        scoretext.setFillColor(sf::Color::White);
        sf::Vector2f position_sc(320.0f+((170.0f-txtSize.x)/2), 65.0f);
        scoretext.setPosition(position_sc);




     /*   std::string scoreboard =  " BATUHAN  "  + to_string(game.score);
        sf::Vector2f scoresize = measureText(scoreboard, font, 38);
        sf::Text scores;
        scores.setFont(font);
        scores.setString(scoretxt);
        scores.setCharacterSize(20);
        scores.setFillColor(sf::Color::White);
        sf::Vector2f position_scorebor(520.0f + ((170.0f - txtSize.x) / 2), 65.0f);
        scoretext.setPosition(position_scorebor);*/

        // -----------------------------------------//

        window.draw(scoretext);
        window.draw(rectangle_nxt);
        window.draw(rectangle_hold);
        game.Draw(window);
        //game.GhostPiece(window);
        window.display();
        
    }

    return 0;
}