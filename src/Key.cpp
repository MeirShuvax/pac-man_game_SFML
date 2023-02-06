#include "Key.h"
#include "Pakman.h"
#include "Door.h"
#include "Board.h"
#include <memory>
#include <iostream>

Key::Key(sf::Vector2f location) :
	StandingObject(location, Resources::resources().getImages().getKeyTexture(), 1) {}
//===============================================
void Key::handleCollision(Pakman& pakman, Board& board)
{
	m_isDead = true;
	int sumDoors = rand() % (sumOfDoors(board) + 1);

	for (int i = 0; i < board.getVectorStanding().size(); ++i)
	{
		auto door = dynamic_cast<Door*>(&(*(board.getVectorStanding()[i])));
		if (door)
		{
			sumDoors--;

			if (sumDoors == 0)
			{
				door->deleteDoor();
				break;
			}

			door = nullptr;
		}
	}
}
//===============================================
int Key::sumOfDoors(Board& board)
{
	int sumDoors = 0;

	for (int i = 0; i < board.getVectorStanding().size(); ++i)
	{
		auto door = dynamic_cast<Door*>(&(*(board.getVectorStanding()[i])));
		if (door)
		{
			sumDoors++;
			door = nullptr;
		}
	}

	return sumDoors;
}