#pragma once
#include "Object.h"


//The role of this department is to manage the moving objects,
//take care of their operation, and implement functions common to them


class MovingObject : public Object
{
public:

	MovingObject(sf::Vector2f location, sf::Texture& texture , float size) ;
	virtual ~MovingObject() = default;
	virtual void makeMove(sf::Vector2u windowSize, sf::Vector2f pakmanLocation) = 0;
	virtual void chengeImage() {};
	virtual void handleCollision(Object& object, Board& board) {};
	void moveToOtherSide(sf::Vector2u windowSize);
	bool collidesWith(const Object& object);
	virtual int getScore() { return EMPTY; };
	virtual int getLife() { return EMPTY; };
	virtual bool isInjured() { return false; };
	void resetTofirstLocation();
	void resetShape();
	void unMove();


protected:
	sf::Clock m_clock;
	sf::Vector2f m_lastStep;
	sf::Vector2f m_firstLocation;
	sf::Clock m_timer;



};
