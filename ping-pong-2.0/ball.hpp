#ifndef BALL_H
#define BALL_H

#include "SFML/Graphics.hpp"
#include<iostream>
#include<cmath>
#include<string>
#include"constants.hpp"
#include"texts.hpp"
#include"SFML/Audio.hpp"
#include "paddle.hpp"

class Ball{
    public:
        float x = screenwidth/2;
        float y = screenheight/2;
        float xSpeed = 0.5;
        float ySpeed = 0.5;
        float radius = 25;
        sf::CircleShape shape;
        sf::Music pointSound;
        sf::Music paddleHitSound;
        sf::Music wallBounceSound;
        sf::Texture texture;

        void setUp();

        void moveSelf();

        void paddleCollision(sf::RectangleShape paddle1,sf::RectangleShape paddle2);

        void wallCollision(Paddle &paddle1,Paddle &paddle2);

        void changeSize(Paddle paddle1, Paddle paddle2);

};


#endif
