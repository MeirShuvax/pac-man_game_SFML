#include "Object.h"
#include <iostream>
//===============================================
Object::Object(sf::Vector2f location, const sf::Texture& texture, float size) :
	m_sprite(texture), m_isDead(false)
{
	m_sprite.setPosition(location.x * PIXEL_SIZE + (PIXEL_SIZE / 2),
		location.y * PIXEL_SIZE + (PIXEL_SIZE / 2));
	m_sprite.setScale(sf::Vector2f(PIXEL_SIZE / m_sprite.getGlobalBounds().width,
		PIXEL_SIZE / m_sprite.getGlobalBounds().height));
	m_sprite.scale( size,  size);
	m_sprite.setOrigin(sf::Vector2f(m_sprite.getTexture()->getSize() / 2u));
}
//===============================================
void Object::drowObject(sf::RenderWindow* window) const
{
	window->draw(m_sprite);
}
//===============================================
sf::Sprite Object::getSprite()const
{
	return m_sprite;
}
//===============================================
bool Object::isDead()
{
	return m_isDead;
}