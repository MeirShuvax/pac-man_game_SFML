#pragma once
#include "Object.h"

//The role of this department is to manage the standing objects,
//take care of their operation, and implement functions common to them


class StandingObject : public Object
{

public:
	StandingObject(sf::Vector2f location, sf::Texture& texture, float size);
	virtual ~StandingObject() = default;
	bool collidesWith(const Object& object) {return false;};

};
