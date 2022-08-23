#ifndef TEXT_H
#define TEXT_H
#include "SFML/Graphics.hpp"
#include<iostream>
#include<cmath>
#include<string>
#include"constants.hpp"
#include"SFML/Audio.hpp"
#include"paddle.hpp"

class ScoreText{

    public:
        sf::Font font;
        sf::Text text;
        int x = 50;
        int y = 25;

    void setUp();
    void update(int score);
};

class Title: public ScoreText{

    public:
        int fontSize = 45;
        int x = (screenwidth/2) - (this->fontSize*3);
        int y = (screenheight)- (this->fontSize*3.5);
        std::string content;
        std::string findWinner(Paddle player1, Paddle player2);
        void setUp();
};

#endif
