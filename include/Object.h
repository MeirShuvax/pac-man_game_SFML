#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Define.h"
#include <memory>
//===============================================
class Board;
class Pakman;
class Cookies;
class Bricks;
class Key;
class Gift;
class Demons;
class Door;
class StandingObject;
class MovingObject;
class GiftAddTime;
class GiftAddLife;
class GiftSuperPakman;
class GiftFreezeDemon;
//===============================================

//The role of this department is to manage all the objects in the game, take care of collisions
//(everyone will do it themselves) and carry out common implementations 
//for everyone (such as - placement and more)

class Object {
public:

	Object(sf::Vector2f location, const sf::Texture& texture, float size);
	virtual ~Object() = default;
	void drowObject(sf::RenderWindow* window) const;
	virtual bool collidesWith(const Object& object ) = 0;
	virtual void handleCollision(Object& object, Board& board) {};
    virtual void handleCollision(Pakman& pakman, Board& board) {};
    virtual void handleCollision(Demons& demones, Board& board) {};
	sf::Sprite getSprite() const;
	bool isDead();


protected:
	sf::Sprite m_sprite;
	bool m_isDead;
	
};