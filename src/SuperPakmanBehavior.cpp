#include "SuperPakmanBehavior.h"
#include "Door.h"


void SuperPakmanBehavior::doorCollision(Pakman& pakman, Door& door)
{
	door.deleteDoor();
}
//===============================================
void SuperPakmanBehavior::demonCollision(Pakman& pakman)
{
	return;
}
//===============================================
void SuperPakmanBehavior::ImageChanger(sf::Sprite& sprite)
{
	if (m_clockImage.getElapsedTime().asSeconds() > 0.4)
	{
		m_clockImage.restart();
		sprite.setTexture(Resources::resources().getImages().getsuperPakmanTexture());
	}
}
//===============================================
bool SuperPakmanBehavior::getMood()
{
	return true;
}
