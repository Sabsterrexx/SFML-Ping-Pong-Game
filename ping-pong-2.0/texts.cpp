#include "texts.hpp"

void ScoreText::setUp(){
        this->font.loadFromFile("mcFont.ttf");
        this->text.setFont(this->font);
        this->text.setString(" ");
        this->text.setOrigin(this->text.getLocalBounds().width/2,text.getLocalBounds().height/2);
        this->text.setPosition(this->x, this->y);
        this->text.setFillColor(sf::Color::Yellow);
    };

void ScoreText::update(int score){
    this->text.setString(std::to_string(score));
};


std::string Title::findWinner(Paddle player1, Paddle player2){
    if(player1.score > player2.score) {
        return "Player 1 wins and Player 2 loses with a score of " + std::to_string(player2.score) + ".";
    } else{
        return "Player 2 wins and Player 1 loses with a score of " + std::to_string(player1.score) + ".";
    }
}

void Title::setUp(){
    this->font.loadFromFile("mcFont.ttf");
    this->text.setFont(this->font);
    this->text.setString(content);
    this->text.setOrigin(this->text.getLocalBounds().width/2,text.getLocalBounds().height/2);
    this->text.setPosition(this->x, this->y);
    this->text.setFillColor(sf::Color::Yellow);
    this->text.setCharacterSize(this->fontSize);
};
