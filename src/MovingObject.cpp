#include "MovingObject.h"

MovingObject::MovingObject(sf::Vector2f location, sf::Texture& texture, float size) :
	Object(location, texture, size), m_firstLocation(location.x* PIXEL_SIZE + (PIXEL_SIZE / 2),
		location.y* PIXEL_SIZE + (PIXEL_SIZE / 2)){}
//===============================================
bool MovingObject::collidesWith(const Object& object)
{
	return(m_sprite.getGlobalBounds().intersects(sf::FloatRect(sf::Vector2f(object.getSprite().getPosition().x
		- (object.getSprite().getGlobalBounds().width / 2) + 3,
		object.getSprite().getPosition().y - (object.getSprite().getGlobalBounds().height / 2) + 3),
		sf::Vector2f(object.getSprite().getGlobalBounds().width - 7,
			object.getSprite().getGlobalBounds().height - 4))));
}
//===============================================
void MovingObject::moveToOtherSide(sf::Vector2u windowSize)
{
	if (m_sprite.getPosition().x > windowSize.x)
		m_sprite.setPosition(0, m_sprite.getPosition().y);

	if (m_sprite.getPosition().x < 0)
		m_sprite.setPosition(windowSize.x, m_sprite.getPosition().y);

	if (m_sprite.getPosition().y > windowSize.y - INFORMATION_DISPLAY)
		m_sprite.setPosition(m_sprite.getPosition().x, 0);

	if (m_sprite.getPosition().y < 0)
		m_sprite.setPosition(m_sprite.getPosition().x, windowSize.y - INFORMATION_DISPLAY);
}
//===============================================
void MovingObject::resetTofirstLocation()
{
	m_sprite.setPosition(m_firstLocation);
}
//==============================================
void MovingObject::resetShape()
{
	m_sprite.setRotation(0);
	if (m_sprite.getScale().x < 0)
		m_sprite.scale(-1, 1);
}
//===============================================
void MovingObject::unMove()
{
	m_sprite.setPosition(m_lastStep);
}




