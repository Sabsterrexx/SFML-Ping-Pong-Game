#ifndef ENDSC_H
#define ENDSC_H

#include <SFML/Graphics.hpp>
#include "paddle.hpp"
#include "ball.hpp"

class EndScreen{

    private:
        sf::RenderWindow *app;
    public:
        EndScreen(sf::RenderWindow &app);
        void display(Paddle &paddle1,Paddle &paddle2, Ball &ball, ScoreText &paddle1Score, ScoreText &paddle2Score);
        void close(sf::Event event);
        void changeState(bool &gameOver, bool &playing, Paddle &paddle1, Paddle &paddle2);

};

#endif
