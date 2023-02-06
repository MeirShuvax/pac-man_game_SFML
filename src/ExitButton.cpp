#include "ExitButton.h"
#include "Define.h"

ExitButton::ExitButton() :
	Buttons("Exit" ,sf::Vector2f(MENU_WIDTH / 2, MENU_HEIGHT / 1.20))
{}
//===============================================
void ExitButton::turnOnButton(sf::RenderWindow& menuWindow, Board& board, bool& isExit)
{
	menuWindow.close();
	board.getWindow()->close();
	isExit = true;
}


