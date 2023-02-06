#include "InformationDisplay.h"
#include "Define.h"
#include <sstream>
#include <string.h>
//===============================================
InformationDisplay::InformationDisplay() :
	m_textScore("0", Resources::resources().getFonts().getFontAriel()), m_Life(Resources::resources().getImages().getPakmanTexture())
	, m_textLevel("", Resources::resources().getFonts().getFontAriel()), m_gameTime("", Resources::resources().getFonts().getFontAriel())
	, m_textLife("", Resources::resources().getFonts().getFontAriel())
{
	setBackground();
	setText();
}
//===============================================
void InformationDisplay::showInformationDisplay(sf::RenderWindow* window)
{
	setPosition(window);
	window->draw(m_background);
	window->draw(m_Life);
	window->draw(m_textLife);
	window->draw(m_textScore);
	window->draw(m_textLevel);
	window->draw(m_gameTime);

}
//===============================================
void InformationDisplay::updateScore(int score)
{
	if (score == -1)
		return;

	m_textScore.setString("    Score: " + std::to_string(score));
}
//===============================================
void InformationDisplay::updateLife(int life)
{
	if (life == -1)
		return;

	m_textLife.setString("x" + std::to_string(life));

}
//===============================================
void InformationDisplay::updateLevel(int level)
{
	m_textLevel.setString("    Level " + std::to_string(level));
}
//===============================================
void InformationDisplay::updateTime(float_t gameTime)
{
	int(gameTime) % 60 >= 10 ? m_gameTime.setString("    Time: " + std::to_string(int(gameTime / 60)) + ':' + std::to_string(int(gameTime) % 60))
		: m_gameTime.setString("    Time: " + std::to_string(int(gameTime / 60)) + ":0" + std::to_string(int(gameTime) % 60));
}
//===============================================
void InformationDisplay::setBackground()
{
	m_background.setFillColor(sf::Color(255, 230, 255, 255));
}
//===============================================
void InformationDisplay::setText()
{
	m_textLevel.setFillColor(sf::Color(204, 0, 0, 255));
	m_textScore.setFillColor(sf::Color(252, 173, 32, 255));
	m_gameTime.setFillColor(sf::Color(249, 35, 76, 255));
	m_textLife.setFillColor(sf::Color(255, 118, 25, 255));
	m_textLevel.setCharacterSize(40);
	m_textScore.setCharacterSize(40);
	m_gameTime.setCharacterSize(40);
	m_textLife.setCharacterSize(40);
	m_Life.setScale(sf::Vector2f(PIXEL_SIZE / m_Life.getGlobalBounds().width,
		PIXEL_SIZE / m_Life.getGlobalBounds().height));
	m_Life.scale(1, 1);
	m_Life.setOrigin(sf::Vector2f(m_Life.getTexture()->getSize() / 2u));
}
//===============================================
void InformationDisplay::setPosition(sf::RenderWindow* window)
{
	m_background.setPosition(0, window->getSize().y - INFORMATION_DISPLAY);
	m_background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	m_Life.setPosition(PIXEL_SIZE / 2, window->getSize().y - INFORMATION_DISPLAY / 2);
	m_textLife.setPosition(m_Life.getPosition().x + m_Life.getGlobalBounds().width / 2,
		window->getSize().y - INFORMATION_DISPLAY);
	m_textLevel.setPosition(m_textLife.getPosition().x + m_textLife.getGlobalBounds().width,
		window->getSize().y - INFORMATION_DISPLAY);
	m_textScore.setPosition(m_textLevel.getPosition().x + m_textLevel.getGlobalBounds().width,
		window->getSize().y - INFORMATION_DISPLAY);
	m_gameTime.setPosition(m_textScore.getPosition().x + m_textScore.getGlobalBounds().width,
		window->getSize().y - INFORMATION_DISPLAY);
}