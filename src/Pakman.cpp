#include "Pakman.h"
#include <iostream>
#include "PakmanBehavior.h"
#include "SuperPakmanBehavior.h"
#include <Windows.h>
//===============================================
Pakman::Pakman(sf::Vector2f location,int dataSaver[]) :
	MovingObject(location, Resources::resources().getImages().getPakmanTexture(), SIZE_MOVINGS), m_score(dataSaver[I_SCORE]),
	m_life(dataSaver[I_LIFE]), m_isInjured(false)
  ,m_behavior(std::make_unique<PakmanBehavior>()){}
//===============================================
//Check the direction Pacman is going, multiply that by
// Pacman's speed, and do the side
//===============================================
void Pakman::makeMove(sf::Vector2u windowSize, sf::Vector2f pakmanLocation)
{
	sf::Vector2f direction;
	m_isInjured = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		resetShape();
		direction = sf::Vector2f(-1, 0);
		m_sprite.scale(-1, 1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		resetShape();
		direction = sf::Vector2f(1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		resetShape();
		direction = sf::Vector2f(0, -1);
		m_sprite.rotate(-90);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		resetShape();
		direction = sf::Vector2f(0, 1);
		m_sprite.rotate(90);
	}
	moveAccordingTime(direction,  windowSize);
}
//===============================================
void Pakman::chengeImage()
{
	m_behavior->ImageChanger(m_sprite);
}
//===============================================
void Pakman::handleCollision(Object& object, Board& board)
{
	object.handleCollision(*this, board);
}
//===============================================
void Pakman::handleCollision(Demons& demon, Board& board)
{
	handleCollisionDemon();
}
//===============================================
void Pakman::addLife()
{
	m_life++;
}
//===============================================
void Pakman::handleCollisionDoor(Door& door)
{
	m_behavior->doorCollision(*this, door);
}
//===============================================
void Pakman::handleCollisionDemon()
{
	m_behavior->demonCollision(*this);
}
//===============================================
void Pakman::addScore()
{
	m_score += 2;
}
//==============================================
void Pakman::becomesSuperPacman()
{
	m_behavior = (std::make_unique<SuperPakmanBehavior>());
	m_sprite.setTexture(Resources::resources().getImages().getsuperPakmanTexture());
	m_timer.restart();
}
//==============================================
void Pakman::resetSuperPakman()
{
	if (m_timer.getElapsedTime().asSeconds() >= SUPER_TIME && m_behavior->getMood())
		m_behavior = (std::make_unique<PakmanBehavior>());
}
//==============================================
void Pakman::reduceLife()
{
	m_life--;
	m_isInjured = true;

	if (m_life == 0)
		m_isDead = true;

	Sleep(500);
}
//==============================================
sf::Vector2f Pakman::getLocation()
{
	return m_sprite.getPosition();
}
//==============================================
int Pakman::getScore()
{
	return m_score;
}
//==============================================
int Pakman::getLife()
{
	return m_life;
}
//==============================================
bool Pakman::isInjured()
{
	return m_isInjured;
}
//==============================================
void Pakman::moveAccordingTime(sf::Vector2f direction, sf::Vector2u windowSize)
{
	const auto deltaTime = m_clock.restart();
	const auto speedPerSecond = 111.f;

	m_lastStep = m_sprite.getPosition();
	m_sprite.move(direction * speedPerSecond * deltaTime.asSeconds());
	moveToOtherSide(windowSize);
	resetSuperPakman();
}
