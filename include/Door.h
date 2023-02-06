#pragma once
#include "StandingObject.h"


class Door : public StandingObject {

public:
	Door(sf::Vector2f location);
	void handleCollision(Pakman& pakman, Board& board) override;
	void handleCollision(Demons& demon, Board& board) ;
	void deleteDoor();

private:

};