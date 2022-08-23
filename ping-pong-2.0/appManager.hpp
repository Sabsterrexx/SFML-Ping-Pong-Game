#ifndef APPMAN_H
#define APPMAN_H

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



class AppManager{

    public:
        void run(Paddle &paddle1, Paddle &paddle2, Ball &ball,float screenheight,float screenwidth,bool &isStarted,bool &gameOver,bool &playing);

};
#endif
