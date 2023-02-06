#include "NewGameButton.h"
#include "Define.h"
#include "Resources.h"

NewGameButton::NewGameButton() :
	Buttons("New game" ,sf::Vector2f(MENU_WIDTH / 2, MENU_HEIGHT / 2)){}
//===============================================
void NewGameButton::turnOnButton(sf::RenderWindow& menuWindow ,Board& board, bool& isExit)
{
	menuWindow.close();
	int dataSaver[3] = {1 , 3 , 0};
	board.resetBoard(dataSaver);
}
