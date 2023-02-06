#include "GiftAddLife.h"
#include "Pakman.h"
//===============================================
GiftAddLife::GiftAddLife(sf::Vector2f location):
    Gift(location) {}
//===============================================
void GiftAddLife::handleCollision(Pakman& pakman, Board& board)
{
    m_isDead = true;
    pakman.addLife();
}