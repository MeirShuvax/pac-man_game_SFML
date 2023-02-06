#include "Demons.h"
#include <iostream>
#include "Pakman.h"
//===============================================
Demons::Demons(sf::Vector2f location, int kind) :
	MovingObject(location, Resources::resources().getImages().getDemonTexture(kind), SIZE_MOVINGS),
	m_isFreeze(false), m_kind(kind) {}
//===============================================
void Demons::makeMove(sf::Vector2u windowSize, sf::Vector2f pakmansLocation)
{
	const auto deltaTime = m_clock.restart();
	if (m_isFreeze)
	{
		resetFreeze();
		return;
	}
	const auto speedPerSecond = 40.f * m_kind;
	m_sprite.move(chasingPacman(windowSize, pakmansLocation) * speedPerSecond * deltaTime.asSeconds());
	moveToOtherSide(windowSize);
}
//===============================================
//The algorithm of the chase will be that it finds the
//distance to Pacman according to x and y and then it will go to what is more equal to it
//===============================================
sf::Vector2f Demons::chasingPacman(sf::Vector2u windowSize, sf::Vector2f pakmansLocation)
{
	sf::Vector2f diraction;
	sf::Vector2f distance;

	diraction.x = getDiractionX(pakmansLocation.x, distance.x, windowSize);
	diraction.y = getDiractionY(pakmansLocation.y, distance.y, windowSize);
	diraction = getTheBestDiraction(diraction, distance);

	m_lastStep = m_sprite.getPosition();
	m_lastDiraction = diraction;
	rotatesTheShape(diraction);
	return diraction;
}
//===============================================
sf::Vector2f Demons::getTheBestDiraction(sf::Vector2f diraction, sf::Vector2f distance)
{
	if (m_lastStep == m_sprite.getPosition())
	{
		if (m_lastDiraction.y == diraction.y)
			diraction.y = 0;
		if (m_lastDiraction.x == diraction.x)
			diraction.x = 0;
	}
	else
	{
		if (distance.y > distance.x)
			diraction.x = 0;
		else
			diraction.y = 0;
	}
	return diraction;
}
//===============================================
float Demons::getDiractionX(float pakmanLocationX, float& distanceX, sf::Vector2u windowSize)
{
	float diractionX;

	if (m_sprite.getPosition().x < pakmanLocationX)
	{
		diractionX = 1;
		distanceX = pakmanLocationX - m_sprite.getPosition().x;
		if (distanceX > windowSize.x - pakmanLocationX + m_sprite.getPosition().x)
		{
			distanceX = windowSize.x - pakmanLocationX + m_sprite.getPosition().x;
			diractionX = -1;
		}
	}
	else
	{
		diractionX = -1;
		distanceX = m_sprite.getPosition().x - pakmanLocationX;
		if (distanceX > windowSize.x - m_sprite.getPosition().x + pakmanLocationX)
		{
			distanceX = windowSize.x - m_sprite.getPosition().x + pakmanLocationX;
			diractionX = 1;
		}
	}
	return diractionX;
}
//===============================================
float Demons::getDiractionY(float pakmanLocationY, float& distanceY, sf::Vector2u windowSize)
{
	float diractionY;

	if (m_sprite.getPosition().y < pakmanLocationY)
	{
		diractionY = 1;
		distanceY = pakmanLocationY - m_sprite.getPosition().y;
		if (distanceY > windowSize.y - pakmanLocationY + m_sprite.getPosition().y)
		{
			distanceY = windowSize.y - pakmanLocationY + m_sprite.getPosition().y;
			diractionY = -1;
		}
	}
	else
	{
		diractionY = -1;
		distanceY = m_sprite.getPosition().y - pakmanLocationY;
		if (distanceY > windowSize.y - m_sprite.getPosition().y + pakmanLocationY)
		{
			distanceY = windowSize.y - m_sprite.getPosition().y + pakmanLocationY;
			diractionY = 1;
		}
	}
	return diractionY;
}
//===============================================
void Demons::rotatesTheShape(sf::Vector2f diraction)
{
	if (diraction.x == 1)
		resetShape();

	if (diraction.x == -1)
	{
		resetShape();
		m_sprite.scale(-1, 1);
	}
}
//===============================================
void Demons::handleCollision(Object& object, Board& board)
{
	object.handleCollision(*this, board);
}
//===============================================
void Demons::handleCollision(Pakman& pakman, Board& board)
{
	pakman.handleCollisionDemon();
}
//===============================================
void Demons::freezeDemon()
{
	m_isFreeze = true;
	m_timer.restart();
	m_sprite.setTexture(Resources::resources().getImages().getDemonTexture(FREEZE_DEMONS));
}
//===============================================
//In each round he will check if it is necessary to change an image such as if he is a frozen elf
//===============================================
void Demons::chengeImage()
{
	if (m_isFreeze)
		flashingFreezeDemone();
	if (!m_isFreeze)
		m_sprite.setTexture(Resources::resources().getImages().getDemonTexture(m_kind));
}
//==============================================
void Demons::flashingFreezeDemone()
{
	if (m_timer.getElapsedTime().asSeconds() >= FREEZE_TIME - 4)
		if (m_flash.getElapsedTime().asSeconds() > 0.3)
		{
			m_sprite.getColor() == sf::Color(0, 0, 0, 0) ? m_sprite.setColor(sf::Color(255, 255, 255, 255)) :
				m_sprite.setColor(sf::Color(0, 0, 0, 0));
			m_flash.restart();
		}
}
//==============================================
void Demons::resetFreeze()
{
	if (m_timer.getElapsedTime().asSeconds() >= FREEZE_TIME && m_isFreeze)
	{
		m_isFreeze = false;
		m_sprite.setColor(sf::Color(255, 255, 255, 255));
	}
}