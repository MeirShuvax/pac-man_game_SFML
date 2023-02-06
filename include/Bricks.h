#pragma once
#include "StandingObject.h"


class Bricks : public StandingObject {

public:

	Bricks(sf::Vector2f location);
	void handleCollision(Pakman& pakman, Board& board) override;
	void handleCollision(Demons& demones, Board& board) override;

private:

};