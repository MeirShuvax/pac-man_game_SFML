#include "Buttons.h"
#include "Font.h"
class NewGameButton :public Buttons
{
public:
	NewGameButton();
	void turnOnButton(sf::RenderWindow& menuWindow ,Board& board, bool& isExit);
};
