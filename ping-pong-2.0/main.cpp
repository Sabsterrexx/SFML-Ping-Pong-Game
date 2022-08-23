#include "SFML/Graphics.hpp"
#include<iostream>
#include<cmath>
#include<string>
#include"ball.hpp"
#include"constants.hpp"
#include"texts.hpp"
#include"SFML/Audio.hpp"
#include "startScreen.hpp"
#include "endScreen.hpp"
#include "gameScreen.hpp"
#include "gameManager.hpp"
#include "appManager.hpp"

bool isStarted = true;
bool playing = false;
bool gameOver = false;

Paddle paddle1;
Paddle paddle2;
Ball ball;

AppManager appManager;

int main(){

    appManager.run(paddle1, paddle2, ball,screenheight,screenwidth,isStarted,gameOver,playing);

}
