#include<appManager.hpp>


void AppManager::run(Paddle &paddle1, Paddle &paddle2, Ball &ball,float screenheight,float screenwidth,bool &isStarted,bool &gameOver,bool &playing){
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(screenwidth, screenheight), "Ping Pong 2.0");
    app.setFramerateLimit(600);
    StartScreen startScreen(app);
    EndScreen endScreen(app);
    GameScreen gameScreen(app);
    GameManager gameManager(app);

	// Start the game loop
    while (app.isOpen()){

        gameManager.manageStart(isStarted,playing,startScreen);


        //ball, paddle and score set up:
        sf::Sprite gameBG;
        sf::Texture gameTexture;
        gameTexture.loadFromFile("gameBackground.png");
        gameBG.setTexture(gameTexture);
        gameBG.setScale(0.75,0.75);

        sf::Music gameMusic;
        gameMusic.openFromFile("gameMusic.ogg");
        gameMusic.play();
        gameMusic.setLoop(true);
        gameMusic.setVolume(25.f);

        ball.setUp();
        paddle1.setUp();
        paddle2.setUp();
        paddle2.x = screenwidth - paddle2.width;
        paddle2.shape.setFillColor(sf::Color::Yellow);
        ScoreText paddle1Score;
        paddle1Score.setUp();
        ScoreText paddle2Score;
        paddle2Score.x = screenwidth-50;
        paddle2Score.setUp();



        gameManager.manageGame(playing,gameOver,gameScreen,paddle1,paddle2,ball,paddle1Score,paddle2Score,gameBG);



        gameManager.manageEnd(gameOver,playing,paddle1,paddle2,ball,paddle1Score,paddle2Score,endScreen);


    }

}
