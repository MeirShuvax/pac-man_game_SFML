#pragma once
#include "StandingObject.h"


class Gift : public StandingObject {

public:
	Gift(sf::Vector2f location);
	virtual ~Gift() = default;
	virtual void handleCollision(Pakman& pakman, Board& board) = 0;
};