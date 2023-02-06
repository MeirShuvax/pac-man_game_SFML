#include "Gift.h"
#include "Pakman.h"
Gift::Gift(sf::Vector2f location) :
    StandingObject(location, Resources::resources().getImages().getGiftTexture(), 1) {}
//===============================================
