#ifndef GAMESC_H
#define GAMESC_H

#include<paddle.hpp>

#include<ball.hpp>
#include<texts.hpp>
#include<SFML/Graphics.hpp>

class GameScreen{

    private:
        sf::RenderWindow *app;
    public:
        GameScreen(sf::RenderWindow &app);
        void setUp(Paddle &paddle1, Paddle &paddle2, Ball &ball,ScoreText &paddle1Score, ScoreText &paddle2Score, sf::Sprite gameBG);
        void update(Paddle &paddle1,Paddle &paddle2,Ball &ball,ScoreText &paddle1Score, ScoreText &paddle2Score);
        void close(sf::Event event);
        void changeState(Paddle paddle1, Paddle paddle2,bool &gameOver, bool &playing);
        void movement(Paddle &paddle1, Paddle &paddle2);

};

#endif
