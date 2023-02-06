#include "HelpButton.h"
#include "Define.h"
#include <thread>
//===============================================
HelpButton::HelpButton() :
	Buttons("Help" ,sf::Vector2f(MENU_WIDTH / 2, MENU_HEIGHT / 1.38)) ,
	m_RectangleHelp(sf::Vector2f(MENU_WIDTH, MENU_HEIGHT)) , m_textHelp(HELP_TEXT, Resources::resources().getFonts().getFontAriel())
{
	m_RectangleHelp.setFillColor(sf::Color(0, 0, 0, 210));
	m_RectangleHelp.setPosition(0, 0);
	m_textHelp.setPosition(70, 70);
	m_textHelp.setCharacterSize(30);
	m_textHelp.setFillColor(sf::Color::White);
}
//===============================================
 void HelpButton::turnOnButton(sf::RenderWindow& menuWindow ,Board& board, bool& isExit)
{
	menuWindow.draw(m_RectangleHelp);
	menuWindow.draw(m_textHelp);
	menuWindow.display();
	using namespace std::chrono_literals;
    std::this_thread::sleep_for(5s);
}


