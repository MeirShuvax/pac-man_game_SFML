#pragma once
#include "MovingObject.h"

//The department is responsible for all the sprites in the game
// for their movement and printing (by inheritance) running after Pacman, etc.

class Demons : public MovingObject {

public:
	Demons(sf::Vector2f location, int kind);
	void makeMove(sf::Vector2u windowSize, sf::Vector2f pakmansLocation) override;
	void handleCollision(Object& object, Board& board) override;
	void handleCollision(Pakman& pakman, Board& board);
	//In each round he will check if it is necessary to change an image such as if he is a frozen elf
	void chengeImage() override;
	void freezeDemon();
	void rotatesTheShape(sf::Vector2f diraction);
	sf::Vector2f getTheBestDiraction(sf::Vector2f diraction, sf::Vector2f distance);
	float getDiractionX(float pakmanLocationX, float& distanceX, sf::Vector2u windowSize);
	float getDiractionY(float pakmanLocationX, float& distanceX, sf::Vector2u windowSize);
	void flashingFreezeDemone();
	void resetFreeze();
	//The algorithm of the chase will be that it finds the
	//distance to Pacman according to x and y and then it will go to what is more equal to it
	sf::Vector2f chasingPacman(sf::Vector2u windowSize, sf::Vector2f pakmansLocation);

private:
	sf::Vector2f m_lastDiraction;
	int m_kind;
	bool m_isFreeze;
	sf::Clock m_flash;
};