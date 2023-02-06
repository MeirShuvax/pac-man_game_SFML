#pragma once
#include <SFML/Graphics.hpp>

class LoadingImages
{
public:
	LoadingImages();
	sf::Texture& getPakmanTexture();
	sf::Texture& getDemonTexture(int kind);
	sf::Texture& getBricksTexture();
	sf::Texture& getCookiesTexture();
	sf::Texture& getDoorTexture();
	sf::Texture& getGiftTexture();
	sf::Texture& getKeyTexture();
	sf::Texture& getMenuTexture();
	sf::Texture& getsuperPakmanTexture();
	sf::Texture& getGameOverTexture();



private:
	sf::Texture m_pakman1;
	sf::Texture m_pakman2;
	sf::Texture m_superPakman1;
	sf::Texture m_superPakman2;
	sf::Texture m_fastDemon;
	sf::Texture m_slowDemon;
	sf::Texture m_mediumDemon;
	sf::Texture m_freezeDemon;
	sf::Texture m_brick;
	sf::Texture m_cookie;
	sf::Texture m_gift;
	sf::Texture m_key;
	sf::Texture m_door;
	sf::Texture m_menu;
	sf::Texture m_gameOver;
	int timeChange;
};
