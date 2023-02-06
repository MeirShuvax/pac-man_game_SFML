#pragma once
#include "Gift.h"

class GiftAddTime : public Gift
{
public:
	GiftAddTime(sf::Vector2f location);
	void handleCollision(Pakman& pakman, Board& board);

};
