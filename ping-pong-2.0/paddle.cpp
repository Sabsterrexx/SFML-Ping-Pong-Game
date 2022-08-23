#include "paddle.hpp"
#include"constants.hpp"

void Paddle::setUp(){
    this->shape.setSize(sf::Vector2f(this->width,this->height));
    this->shape.setOrigin(this->width/2,this->height/2);
    this->shape.setPosition(this->x,this->y);
    this->shape.setFillColor(sf::Color::Green);
}

void Paddle::wallCollision(){
    if(this->y < this->height/2) this->y = this->height/2;
    if(this->y >  screenheight - this-> height/2) this->y = screenheight - this->height/2;
}
