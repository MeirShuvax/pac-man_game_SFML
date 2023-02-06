#pragma once
#include <SFML/Graphics.hpp>

class Font
{
public:
	Font();
	sf::Font& getFontAriel();

private:
	sf::Font m_fontAriel;
	
};
