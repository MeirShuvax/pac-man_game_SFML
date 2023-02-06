#pragma once
#include <SFML/Graphics.hpp>
#include "LoadingImages.h"
#include "Resources.h"

class Pakman;
class Door;

//This department's job is to manage the situations of Pacman and Super Pacman,
//and to do the things that are different between them

class PakmanBaseBehavior
{
public:

	virtual ~PakmanBaseBehavior() = default;
	virtual void doorCollision(Pakman& pakman, Door& door) = 0;
	virtual void demonCollision(Pakman& pakman) = 0;
	virtual void ImageChanger(sf::Sprite& sprite) = 0;
	virtual bool getMood() = 0;


protected:
	sf::Clock m_clockImage;
};



