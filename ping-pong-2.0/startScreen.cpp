#include "startScreen.hpp"
#include "SFML/Graphics.hpp"
#include "texts.hpp"


StartScreen::StartScreen(sf::RenderWindow &app){

    this->app = &app;

}


void StartScreen::display(){

        Title startText;
        startText.content = "Welcome to Ping Pong, press 'Space' to start.\nPlayer 1 is on the left, Player 2 is on the right.";
        startText.setUp();

        sf::Sprite startBG;
        sf::Texture startTexture;
        startTexture.loadFromFile("startBackground.jpg");
        startBG.setTexture(startTexture);
        startBG.setScale(0.70,0.75);
        startBG.move(-70,0);

        app->clear(sf::Color::White);
        app->draw(startBG);
        app->draw(startText.text);
        app->display();

}

void StartScreen::close(sf::Event event){

            while (app->pollEvent(event))
            // Close window : exit
                if (event.type == sf::Event::Closed )
                    app->close();

}

void StartScreen::changeState(bool &isStarted,bool &playing){

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                isStarted = false;
                playing = true;
            }

}
