#include<gameScreen.hpp>

GameScreen::GameScreen(sf::RenderWindow &app){

    this->app = &app;

}


void GameScreen::setUp(Paddle &paddle1,Paddle &paddle2,Ball &ball,ScoreText &paddle1Score, ScoreText &paddle2Score,sf::Sprite gameBG){

            app->clear(sf::Color::White);

            //positions:
            paddle1.shape.setPosition(paddle1.x,paddle1.y);
            paddle2.shape.setPosition(paddle2.x,paddle2.y);

            ball.changeSize(paddle1,paddle2);

            // Draw the sprite
            app->draw(gameBG);
            app->draw(ball.shape);
            app->draw(paddle1.shape);
            app->draw(paddle2.shape);
            app->draw(paddle1Score.text);
            app->draw(paddle2Score.text);


}

void GameScreen::update(Paddle &paddle1,Paddle &paddle2,Ball &ball,ScoreText &paddle1Score, ScoreText &paddle2Score){

            //ball borders:
            ball.wallCollision(paddle1,paddle2);
            paddle1Score.update(paddle1.score);
            paddle2Score.update(paddle2.score);

            paddle1.wallCollision();
            paddle2.wallCollision();

            //paddle and ball collision:
            ball.paddleCollision(paddle1.shape,paddle2.shape);

            // Update the window
            app->display();
            ball.moveSelf();
}

void GameScreen::close(sf::Event event){
            while (app->pollEvent(event))
            // Close window : exit
                if (event.type == sf::Event::Closed )
                    app->close();
}

void GameScreen::changeState(Paddle paddle1, Paddle paddle2, bool &gameOver, bool &playing){

    if(paddle1.score  == 10 || paddle2.score == 10){
                sf::sleep(sf::milliseconds(500));
                gameOver = true;
                playing = false;
    }

}

void GameScreen::movement(Paddle &paddle1, Paddle &paddle2){

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){

            paddle1.y -= paddle1.speed;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){

            paddle1.y += paddle1.speed;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){

            paddle2.y -= paddle2.speed;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){

            paddle2.y += paddle2.speed;

        }

}
