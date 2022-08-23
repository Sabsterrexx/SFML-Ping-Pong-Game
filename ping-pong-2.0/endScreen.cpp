#include "endScreen.hpp"
#include "texts.hpp"
#include "paddle.hpp"
#include "ball.hpp"

EndScreen::EndScreen(sf::RenderWindow &app){

    this->app = &app;

}


void EndScreen::display(Paddle &paddle1,Paddle &paddle2, Ball &ball, ScoreText &paddle1Score, ScoreText &paddle2Score){

        Title winnerText;
        winnerText.content = winnerText.findWinner(paddle1,paddle2);
        winnerText.x = screenwidth/3;
        winnerText.y = screenheight/4;
        winnerText.setUp();

        Title endText;
        endText.content = "Game Over. Press 'space' to play again.";
        endText.x = (screenwidth/2) - (endText.fontSize*3);
        endText.y = screenheight/2;
        endText.setUp();

        sf::Sprite endBG;
        sf::Texture endTexture;
        endTexture.loadFromFile("endBackground.png");
        endBG.setTexture(endTexture);
        endBG.setScale(1.5,1.5);

        paddle1Score.text.setString("");
        paddle2Score.text.setString("");
        paddle1.y = screenheight/2;
        paddle2.y = screenheight/2;
        ball.x = screenheight/2;
        ball.y = screenwidth/2;
        ball.radius = 25;

        app->clear(sf::Color::White);

        app->draw(endBG);
        app->draw(endText.text);
        app->draw(winnerText.text);

        app->display();


}


void EndScreen::close(sf::Event event){

            while (app->pollEvent(event))
            // Close window : exit
                if (event.type == sf::Event::Closed )
                    app->close();

}

void EndScreen::changeState(bool &gameOver, bool &playing, Paddle &paddle1, Paddle &paddle2){

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                paddle1.score = 0;
                paddle2.score = 0;
                gameOver = false;
                playing = true;

    }

}


