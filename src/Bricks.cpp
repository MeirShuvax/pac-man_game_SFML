#include "Bricks.h"
#include "MovingObject.h"
#include <iostream>
#include "Demons.h"
#include "Pakman.h"
#include "Resources.h"
Bricks::Bricks(sf::Vector2f location):
    StandingObject(location, Resources::resources().getImages().getBricksTexture(), 1) {}
//===============================================
void Bricks::handleCollision(Pakman& pakman, Board& board)
{
    pakman.unMove();
}
//===============================================
void Bricks::handleCollision(Demons& demones, Board& board)
{
    demones.unMove();
}
