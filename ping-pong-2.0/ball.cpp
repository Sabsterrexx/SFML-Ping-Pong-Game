#include <ball.hpp>
#include<paddle.hpp>
#include<constants.hpp>
#include<SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

void Ball::setUp(){
        this->texture.loadFromFile("enderPearl.png");
        this->shape.setRadius(this->radius);
        this->shape.setOrigin(this->radius,this->radius);
        this->shape.setTexture(&this->texture);

}

void Ball::moveSelf(){
    this->shape.setPosition(this->x,this->y);
    this->x += this->xSpeed;
    this->y += this->ySpeed;
}

void Ball::paddleCollision(sf::RectangleShape paddle1,sf::RectangleShape paddle2){

    if(this->shape.getGlobalBounds().intersects(paddle1.getGlobalBounds())){
        this->paddleHitSound.openFromFile("paddleStrike.ogg");
        this->paddleHitSound.play();
        this->ySpeed = (this->shape.getPosition().y - paddle1.getPosition().y)/65.0*0.6;
        this->xSpeed = sqrt(pow(0.71,2) - pow(this->ySpeed,2));

    } else if(this->shape.getGlobalBounds().intersects(paddle2.getGlobalBounds())){
        this->paddleHitSound.openFromFile("paddleStrike.ogg");
        this->paddleHitSound.play();
        this->ySpeed = (this->shape.getPosition().y - paddle2.getPosition().y)/65.0*0.6;
        this->xSpeed = sqrt(pow(0.71,2) - pow(this->ySpeed,2)) * -1;
    }

}

void Ball::wallCollision(Paddle &paddle1,Paddle &paddle2){

    if(this->radius > this->x){
        this->x = screenwidth/2;
        paddle2.score++;
        this->pointSound.openFromFile("point.ogg");
        this->pointSound.play();
     } else if (this->x > screenwidth - this->radius) {
        this->x = screenwidth/2;
        paddle1.score++;
        this->pointSound.openFromFile("point.ogg");
        this->pointSound.play();
    }

    if(this->radius > this->y  || this->y > screenheight - this->radius){
        this->ySpeed *= -1;
        wallBounceSound.openFromFile("wallBounce.ogg");
        wallBounceSound.play();
    }

}

void Ball::changeSize(Paddle paddle1, Paddle paddle2){

        if(paddle1.score > 3 || paddle2.score > 3){

            this->radius = 20;

        } else if (paddle1.score > 5 || paddle2.score > 5){

            this->radius = 15;

        } else if (paddle1.score > 7 || paddle2.score > 7){

            this->radius = 10;

        }

    }
