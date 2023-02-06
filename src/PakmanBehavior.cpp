#include "PakmanBehavior.h"
#include "Pakman.h"
#include <iostream>
void PakmanBehavior::doorCollision(Pakman& pakman, Door& door)
{
	pakman.unMove();
}
//===============================================
void PakmanBehavior::demonCollision(Pakman& pakman)
{
	pakman.reduceLife();
}
//===============================================
void PakmanBehavior::ImageChanger(sf::Sprite& sprite)
{
	if (m_clockImage.getElapsedTime().asSeconds() > 0.4)
	{
		m_clockImage.restart();
		sprite.setTexture(Resources::resources().getImages().getPakmanTexture());
	}
}
//===============================================
bool PakmanBehavior::getMood()
{
	return false;
}
