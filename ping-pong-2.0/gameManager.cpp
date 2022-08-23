#include <gameManager.hpp>


GameManager::GameManager(sf::RenderWindow &app){

    this->app = &app;


}

void GameManager::manageStart(bool &isStarted, bool &playing,StartScreen startScreen){

    while (isStarted){
            sf::Event event;
            startScreen.close(event);
            startScreen.changeState(isStarted,playing);
            startScreen.display();
        }

}


void GameManager::manageEnd(bool &gameOver,bool &playing,Paddle &paddle1, Paddle &paddle2, Ball &ball, ScoreText &paddle1Score, ScoreText &paddle2Score,EndScreen endScreen){

    while (gameOver){
            sf::Event event;
            endScreen.close(event);
            endScreen.changeState(gameOver,playing,paddle1,paddle2);
            endScreen.display(paddle1,paddle2,ball,paddle1Score,paddle2Score);
        }


}


void GameManager::manageGame(bool &playing,bool &gameOver,GameScreen gameScreen,Paddle &paddle1,Paddle &paddle2,Ball &ball,ScoreText &paddle1Score,ScoreText &paddle2Score,sf::Sprite gameBG){

    while (playing){
            sf::Event event;
            gameScreen.close(event);
            gameScreen.setUp(paddle1,paddle2,ball,paddle1Score,paddle2Score,gameBG);
            gameScreen.movement(paddle1,paddle2);
            gameScreen.changeState(paddle1,paddle2,gameOver,playing);
            gameScreen.update(paddle1,paddle2,ball,paddle1Score,paddle2Score);
        }
}
