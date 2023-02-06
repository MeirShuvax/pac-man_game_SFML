#include "Buttons.h"
#include "Font.h"

class ExitButton :public Buttons
{
public:
	ExitButton();
	void turnOnButton(sf::RenderWindow& menuWindow, Board& board, bool& isExit) override;

};
