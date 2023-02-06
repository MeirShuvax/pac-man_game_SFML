#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"


//The role of this department is to manage the game display board


class InformationDisplay
{
public:
	InformationDisplay();
	void showInformationDisplay(sf::RenderWindow* window);
	void updateScore(int score);
	void updateLife(int life);
	void updateLevel(int level);
	void updateTime(float_t gameTime);
	void setBackground();
	void setText();
	void setPosition(sf::RenderWindow* window);


private:
	sf::Text m_textScore;
	sf::Text m_textLevel;
	sf::Sprite m_Life;
	sf::Text m_textLife;
	sf::Text m_gameTime;
	sf::RectangleShape m_background;

};