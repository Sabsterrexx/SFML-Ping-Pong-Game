#ifndef GAMEMAN_H
#define GAMEMAN_H

#include <startScreen.hpp>
#include <gameScreen.hpp>
#include <endScreen.hpp>
#include <paddle.hpp>
#include<ball.hpp>
#include<texts.hpp>

class GameManager{

    private:
        sf::RenderWindow *app;

    public:
        GameManager(sf::RenderWindow &app);
        void manageStart(bool &isStarted, bool &playing,StartScreen startScreen);
        void manageGame(bool &playing,bool &gameOver,GameScreen gameScreen,Paddle &paddle1,Paddle &paddle2,Ball &ball,ScoreText &paddle1Score,ScoreText &paddle2Score,sf::Sprite gameBG);
        void manageEnd(bool &gameOver,bool &playing,Paddle &paddle1, Paddle &paddle2, Ball &ball, ScoreText &paddle1Score, ScoreText &paddle2Score,EndScreen endScreen);
};

#endif
