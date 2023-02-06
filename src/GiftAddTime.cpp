#include "GiftAddTime.h"
#include "Pakman.h"
#include "Board.h"
//===============================================
GiftAddTime::GiftAddTime(sf::Vector2f location) :
    Gift(location) {}
//===============================================
void GiftAddTime::handleCollision(Pakman& pakman, Board& board)
{
    m_isDead = true;
    board.getTimer().addTime(GIFT_ADD_TIME);
}