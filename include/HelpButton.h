#include "Buttons.h"
#include "Font.h"
class HelpButton :public Buttons
{
public:
	HelpButton();
	void turnOnButton(sf::RenderWindow& menuWindow, Board& board, bool& isExit) override;

private:
	sf::RectangleShape m_RectangleHelp;
	sf::Text m_textHelp;
};
