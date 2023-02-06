#include "Timer.h"
#include <iostream>
//===============================================
Timer::Timer() :
	m_maxTime((rand() % 6) + 5) {}
//===============================================
bool Timer::isEndTime()
{
	return countingDown() <= 0;
}
//===============================================
float Timer::countingDown()
{
	return (float(m_maxTime * 60) - m_gameTime.getElapsedTime().asSeconds());
}
//===============================================
void Timer::addTime(int plusTime)
{
	m_maxTime += plusTime / 60;
	float seconds = plusTime % 60;
	m_maxTime += seconds / 60;
}
//===============================================
void Timer::resetTime()
{
	m_gameTime.restart();
}