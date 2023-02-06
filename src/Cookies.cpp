#include "Cookies.h"
//#include<iostream>
#include "Pakman.h"
#include <Windows.h>
#include <thread>
//===============================================
Cookies::Cookies(sf::Vector2f location) :
    StandingObject(location, Resources::resources().getImages().getCookiesTexture(), 1){}
//===============================================
void Cookies::handleCollision(Pakman& pakman, Board& board)
{
    m_isDead = true;
    pakman.addScore();
}
