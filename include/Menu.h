#pragma once
#include "Resources.h"
#include "Board.h"
#include "Buttons.h"


//The role of this department is to manage the game menu,
//and make sure that the actions are performed according to the player's click


class Menu
{
public:
	Menu();
	void setArrow();//Creates a marker arrow
	void setButtons();//
	void openMenu(Board& board, bool& isExit);
	void drowMenu(sf::RenderWindow& menuWindow);
	void isMouseMoved(const sf::Event& event);
	void isMousReleased(const sf::Event& event, sf::RenderWindow& menuWindow, Board& board, bool& isExit);
	void isKeyPressed(const sf::Event& event, sf::RenderWindow& menuWindow, Board& board, bool& isExit);
	//Moves the cursor backand forth
	void isUpPressed();
	//Moves the cursor backand forth
	void isDownPressed();
	void flashingArrow();
	void resetfirstbutton();



private:
	sf::Sprite m_menu;
	//Vector of menu buttons
	std::vector < std::unique_ptr<Buttons>> m_buttons;
	sf::ConvexShape m_arrow;
	sf::Clock m_arrowClock;

};