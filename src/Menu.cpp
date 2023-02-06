#include "Menu.h"
#include "Define.h"
#include "NewGameButton.h"
#include "HelpButton.h"
#include "ExitButton.h"
#include "ContinueButton.h"
//===============================================
Menu::Menu() :
	m_menu(Resources::resources().getImages().getMenuTexture())
{
	setButtons();
	setArrow();
}
//===============================================
void Menu::setButtons()
{
	m_buttons.push_back(std::make_unique<NewGameButton>());
	m_buttons.push_back(std::make_unique<ContinueButton>());
	m_buttons.push_back(std::make_unique<HelpButton>());
	m_buttons.push_back(std::make_unique<ExitButton>());
}
//===============================================
void Menu::setArrow()
{
	m_arrow.setPointCount(7);
	m_arrow.setPoint(0, sf::Vector2f(0, 20));
	m_arrow.setPoint(1, sf::Vector2f(20, 40));
	m_arrow.setPoint(2, sf::Vector2f(20, 30));
	m_arrow.setPoint(3, sf::Vector2f(50, 30));
	m_arrow.setPoint(4, sf::Vector2f(50, 10));
	m_arrow.setPoint(5, sf::Vector2f(20, 10));
	m_arrow.setPoint(6, sf::Vector2f(20, 0));
	m_arrow.setFillColor(sf::Color::Red);
	m_arrow.setOutlineColor(sf::Color::Black);
	m_arrow.setOutlineThickness(4);
}
//===============================================
void Menu::openMenu(Board& board, bool& isExit)
{
	auto menuWindow = sf::RenderWindow(sf::VideoMode((MENU_WIDTH), (MENU_HEIGHT)), "Menu");
	while (menuWindow.isOpen())
	{
		resetfirstbutton();
		drowMenu(menuWindow);
		menuWindow.display();
		for (auto event = sf::Event{}; menuWindow.pollEvent(event); )
			switch (event.type)
			{
			case sf::Event::Closed:
				menuWindow.close();
				isExit = true;
				break;

			case sf::Event::KeyPressed:
				isKeyPressed(event, menuWindow, board, isExit);
				break;

			case sf::Event::MouseMoved:
				isMouseMoved(event);
				break;

			case sf::Event::MouseButtonReleased:
				isMousReleased(event, menuWindow, board, isExit);
				break;
			}
	}
}
//===============================================
void Menu::drowMenu(sf::RenderWindow& menuWindow)
{
	flashingArrow();
	menuWindow.draw(m_menu);
	menuWindow.draw(m_arrow);

	for (int cell = 0; cell < m_buttons.size(); ++cell)
		m_buttons[cell]->drowButton(menuWindow);
}
//===============================================
void Menu::isMouseMoved(const sf::Event& event)
{
	for (int cell = 0; cell < m_buttons.size(); ++cell)
		if (m_buttons[cell]->isButtonPressed(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)))
			m_buttons[cell]->highlightsButton(m_arrow);
		else
			m_buttons[cell]->resetHighlightsButton();
}
//===============================================
void Menu::isMousReleased(const sf::Event& event, sf::RenderWindow& menuWindow,
	Board& board, bool& isExit)
{
	for (int cell = 0; cell < m_buttons.size(); ++cell)
		if (m_buttons[cell]->isButtonPressed(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
			m_buttons[cell]->turnOnButton(menuWindow, board, isExit);
}
//===============================================
//Moves the cursor backand forth
void Menu::isKeyPressed(const sf::Event& event, sf::RenderWindow& menuWindow,
	Board& board, bool& isExit)
{
	switch (event.key.code)
	{

	case sf::Keyboard::Up:
		isUpPressed();
		break;

	case sf::Keyboard::Down:
		isDownPressed();
		break;

	case sf::Keyboard::Enter:
		for (int cell = 0; cell < m_buttons.size(); ++cell)
			if (m_buttons[cell]->isPressedNow())
				m_buttons[cell]->turnOnButton(menuWindow, board, isExit);
		break;
	}
}
//===============================================
void Menu::isUpPressed()//Moves the cursor backand forth
{
	for (int cell = 0; cell < m_buttons.size(); ++cell)
		if (m_buttons[cell]->isPressedNow())
		{
			m_buttons[cell]->resetHighlightsButton();
			if (cell - 1 == -1)
				cell = m_buttons.size() - 1;
			else
				cell -= 1;
			m_buttons[cell]->highlightsButton(m_arrow);
		}
}
//===============================================
void Menu::isDownPressed()//Moves the cursor backand forth
{
	for (int cell = 0; cell < m_buttons.size(); ++cell)
		if (m_buttons[cell]->isPressedNow())
		{
			m_buttons[cell]->resetHighlightsButton();
			if (cell + 1 == m_buttons.size())
				cell = 0;
			else
				cell += 1;
			m_buttons[cell]->highlightsButton(m_arrow);
		}
}
//===============================================
void Menu::flashingArrow()
{
	if (m_arrowClock.getElapsedTime().asSeconds() > 0.8)
	{
		m_arrowClock.restart();
		if (m_arrow.getFillColor() == sf::Color(0, 0, 0, 0))
		{
			m_arrow.setOutlineColor(sf::Color::Black);
			m_arrow.setFillColor(sf::Color::Red);
		}
		else
		{
			m_arrow.setFillColor(sf::Color(0, 0, 0, 0));
			m_arrow.setOutlineColor(sf::Color(0, 0, 0, 0));
		}
	}
}
//===============================================
void Menu::resetfirstbutton()
{
	for (int cell = 0; cell < m_buttons.size(); ++cell)
		if (m_buttons[cell]->isPressedNow())
			return;
	m_buttons[0]->highlightsButton(m_arrow);
}
//===============================================