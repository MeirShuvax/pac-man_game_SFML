#include "Buttons.h"
#include "Font.h"
class ContinueButton :public Buttons
{
public:
	ContinueButton();
	void turnOnButton(sf::RenderWindow& menuWindow, Board& board, bool& isExit) override;
};
