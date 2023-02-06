#pragma once
#include "Gift.h"

class GiftSuperPakman : public Gift
{
public:
	GiftSuperPakman(sf::Vector2f location);
	void handleCollision(Pakman& pakman, Board& board);

private:

};
