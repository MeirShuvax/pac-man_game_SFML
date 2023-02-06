#include "Door.h"
#include "Pakman.h"
#include "Demons.h"
//===============================================
Door::Door(sf::Vector2f location) :
    StandingObject(location, Resources::resources().getImages().getDoorTexture(), 1) {}
//===============================================
void Door::deleteDoor()
{
    m_isDead = true;
}
//===============================================
void Door::handleCollision(Pakman& pakman, Board& board)
{
    pakman.handleCollisionDoor(*this);
}
//===============================================
void Door::handleCollision(Demons& demon, Board& board)
{
    demon.unMove();
}

