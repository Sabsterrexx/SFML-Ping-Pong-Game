#ifndef PADDLE_H
#define PADDLE_H

#include "SFML/Graphics.hpp"
#include<iostream>
#include<cmath>
#include<string>
#include"constants.hpp"
#include"SFML/Audio.hpp"

class Paddle{
    public:
        float x = 20;
        float y = screenheight/2;
        float width = 15;
        float height = 100;
        float speed = 0.5;
        int score = 0;
        sf::RectangleShape shape;
        void setUp();
        void wallCollision();
};

#endif
