#include "LoadingImages.h"
#include "Define.h"
#include <iostream>
//===============================================
LoadingImages::LoadingImages():
	timeChange(0)
{
	m_pakman1.loadFromFile("Pakman1.png");
	m_pakman2.loadFromFile("Pakman2.png");
	m_superPakman1.loadFromFile("superPakman1.png");
	m_superPakman2.loadFromFile("superPakman2.png");
	m_mediumDemon.loadFromFile("DemonYellow.png");
	m_fastDemon.loadFromFile("DemonRed.png");
	m_slowDemon.loadFromFile("DemonGreen.png");
	m_freezeDemon.loadFromFile("DemonBlue.png");
	m_brick.loadFromFile("Bricks.png");
	m_key.loadFromFile("Key.png");
	m_cookie.loadFromFile("Cookies.png");
	m_door.loadFromFile("Door.png");
	m_gift.loadFromFile("Gift.png");
	m_menu.loadFromFile("Menu.png");
	m_gameOver.loadFromFile("GameOver.png");
}
//===============================================
sf::Texture& LoadingImages::getPakmanTexture()
{
	timeChange++;
	if (timeChange == 2)
		timeChange = 0;
	return timeChange == 0 ? m_pakman1 : m_pakman2;
}
//===============================================
sf::Texture& LoadingImages::getsuperPakmanTexture()
{
	timeChange++;
	if (timeChange == 2)
		timeChange = 0;
	return timeChange == 0 ? m_superPakman1 : m_superPakman2;
}
//===============================================
sf::Texture& LoadingImages::getDemonTexture(int kind)
{
	return kind == FREEZE_DEMONS ? m_freezeDemon : kind == SLOW_DEMONE ? m_slowDemon :
		kind == MEDIUM_DEMONE ? m_mediumDemon : m_fastDemon;
}
//===============================================
sf::Texture& LoadingImages::getBricksTexture()
{
	return m_brick;
}
//===============================================
sf::Texture& LoadingImages::getKeyTexture()
{
	return m_key;
}
//===============================================
sf::Texture& LoadingImages::getCookiesTexture()
{
	return m_cookie;
}
//===============================================
sf::Texture& LoadingImages::getDoorTexture()
{
	return m_door;
}
//===============================================
sf::Texture& LoadingImages::getGiftTexture()
{
	return m_gift;
}
//===============================================
sf::Texture& LoadingImages::getMenuTexture()
{
	return m_menu;
}
//===============================================
sf::Texture& LoadingImages::getGameOverTexture()
{
	return m_gameOver;
}

