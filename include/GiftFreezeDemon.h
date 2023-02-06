#pragma once
#include "Gift.h"

class GiftFreezeDemon : public Gift
{
public:
	GiftFreezeDemon(sf::Vector2f location);
	void handleCollision(Pakman& pakman, Board& board);

private:

};
