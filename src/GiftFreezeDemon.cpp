#include "GiftFreezeDemon.h"
#include "Board.h"
#include "Demons.h"

GiftFreezeDemon::GiftFreezeDemon(sf::Vector2f location) :
	Gift(location) {}
//===============================================
void GiftFreezeDemon::handleCollision(Pakman& pakman, Board& board)
{
	m_isDead = true;

	for (int i = 0; i < board.getVectorMoving().size(); ++i)
	{
		auto demons = dynamic_cast<Demons*>(&(*(board.getVectorMoving()[i])));
		if (demons)
			demons->freezeDemon();
	}
}