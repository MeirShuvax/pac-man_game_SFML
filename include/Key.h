#pragma once
#include "StandingObject.h"


class Key : public StandingObject {

public:
	Key(sf::Vector2f location);
	void handleCollision(Pakman& pakman, Board& board) override;
	int sumOfDoors(Board& board);

private:

};