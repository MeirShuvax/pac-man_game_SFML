#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class Sound
{
public:
	Sound();
    sf::Music& getGameSound();


private:

	sf::Music m_pakmanBuffer;

};