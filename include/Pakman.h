#pragma once
#include "MovingObject.h"
#include "PakmanBaseBehavior.h"

//This department's job is to manage Pacman, 
//its conflicts, and everything related to it


class Pakman : public MovingObject 
{

public:
	Pakman(sf::Vector2f location, int dataSaver[]);
	void makeMove(sf::Vector2u windowSize, sf::Vector2f pakmanLocation) override;
	void chengeImage() override;
	void handleCollision(Object& object, Board& board) override;
	void handleCollision(Demons& demon, Board& board);
	void handleCollisionDoor(Door& door);
	void handleCollisionDemon();
	void addScore();
	void addLife();
	void becomesSuperPacman();
	void reduceLife();
	void resetSuperPakman();
	int getScore();
	int getLife();
	bool isInjured();
	sf::Vector2f getLocation();
	void moveAccordingTime(sf::Vector2f direction, sf::Vector2u windowSize);


private:
	int m_score;
	int m_life;
	bool m_isInjured;
	std::unique_ptr <PakmanBaseBehavior> m_behavior;

};




