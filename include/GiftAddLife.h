#pragma once
#include "Gift.h"

class GiftAddLife : public Gift
{
public:
	GiftAddLife(sf::Vector2f location);
	void handleCollision(Pakman& pakman, Board& board);

private:
   
};
