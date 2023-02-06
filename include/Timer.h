#pragma once
#include <SFML/Graphics.hpp>

class Timer
{
public:

	Timer();
	bool isEndTime();
	float countingDown();
	void addTime(int plusTime);
	void resetTime();


private:
	sf::Clock m_gameTime;
	float m_maxTime;
};