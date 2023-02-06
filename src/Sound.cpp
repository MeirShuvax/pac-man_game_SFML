#include "Sound.h"

Sound::Sound()
{
	m_pakmanBuffer.openFromFile("Pakman.wav");
}
//===============================================
sf::Music& Sound::getGameSound()
{
	return m_pakmanBuffer;
}
//===============================================