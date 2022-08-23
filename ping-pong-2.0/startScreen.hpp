#ifndef STARTSC_H
#define STARTSC_H

#include "SFML/Graphics.hpp"


class StartScreen{
    private:
        sf::RenderWindow *app;
    public:
        StartScreen(sf::RenderWindow &app);
        void display();
        void close(sf::Event event);
        void changeState(bool &isStarted,bool &playing);
};


#endif
