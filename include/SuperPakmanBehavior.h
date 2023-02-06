#pragma once
#include "PakmanBaseBehavior.h"

//In case of differences between the Pacman and the author,
//here it is according to the super Pacman

class SuperPakmanBehavior : public PakmanBaseBehavior
{
public:
	void doorCollision(Pakman& pakman, Door& door) override;
	void demonCollision(Pakman& pakman) override;
	void ImageChanger( sf::Sprite& sprite)override;
	bool getMood()override;


private:

};
