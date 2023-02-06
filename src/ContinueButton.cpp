#include "ContinueButton.h"
#include "Define.h"

ContinueButton::ContinueButton() :
	Buttons("Continue",  sf::Vector2f(MENU_WIDTH / 2, MENU_HEIGHT / 1.63))
{}
//===============================================
void ContinueButton::turnOnButton(sf::RenderWindow& menuWindow, Board& board,bool & isExit)
{
	menuWindow.close();
}


