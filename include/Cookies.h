#pragma once
#include "StandingObject.h"
#include <SFML/Audio.hpp>


class Cookies : public StandingObject {

public:
	Cookies(sf::Vector2f location);
	void handleCollision(Pakman& pakman, Board& board) override;

private:
	sf::Sound m_eate;
};