#include "GiftSuperPakman.h"
#include "Pakman.h"
//===============================================
GiftSuperPakman::GiftSuperPakman(sf::Vector2f location) :
    Gift(location) {}
//===============================================
void GiftSuperPakman::handleCollision(Pakman& pakman, Board& board)
{
    m_isDead = true;
    pakman.becomesSuperPacman();
}