#include "Buttons.h"

//An abstract class that assigns to each button
//in the menu
//And the different functions for each button realized by virtual
//===============================================
Buttons::Buttons(const char buttonName[], sf::Vector2f Location) :
	m_text(buttonName, Resources::resources().getFonts().getFontAriel()), m_pressedNow(false),
	m_color(sf::Color(204, 51, 0, 255)), m_defaultColor(sf::Color(0, 160, 204, 255))
{
	setText(Location);
	setRectangle();
}					
//===============================================
void Buttons::setText(sf::Vector2f Location)
{
	m_text.setPosition(Location);
	m_text.setCharacterSize(75);
	m_text.setFillColor(m_defaultColor);
	m_text.setOrigin(m_text.getGlobalBounds().width / 2, m_text.getGlobalBounds().height / 2);
}
//===============================================
void Buttons::setRectangle()
{
	m_rectangle.setSize(sf::Vector2f(m_text.getGlobalBounds().width, m_text.getGlobalBounds().height + 5));
	m_rectangle.setPosition(m_text.getPosition().x, m_text.getPosition().y + m_text.getGlobalBounds().height / 2);
	m_rectangle.setFillColor(sf::Color(0, 0, 0, 0));
	m_rectangle.setOrigin(m_rectangle.getGlobalBounds().width / 2, m_rectangle.getGlobalBounds().height / 2 + 5);
}
//===============================================
void Buttons::drowButton(sf::RenderWindow& menuWindow)
{
	menuWindow.draw(m_text);
	menuWindow.draw(m_rectangle);
}
//===============================================
//A function responsible for highlighting as open the cursor on it
void Buttons::highlightsButton(sf::ConvexShape& m_arrow)
{
	m_arrow.setPosition(m_text.getPosition().x + m_text.getGlobalBounds().width / 2 + 20,
		m_text.getPosition().y + m_text.getGlobalBounds().height / 2 - 20);

	m_pressedNow = true;
	m_text.setFillColor(m_color);
	m_rectangle.setFillColor(sf::Color(0, 0, 0, 20));

}
//===============================================
void Buttons::resetHighlightsButton()
{
	m_pressedNow = false;

	m_text.setFillColor(m_defaultColor);
	m_rectangle.setFillColor(sf::Color(0, 0, 0, 0));
	m_rectangle.setOutlineColor(sf::Color(0, 0, 0, 0));

}
//===============================================
bool Buttons::isPressedNow()
{
	return m_pressedNow;
}
//===============================================
bool Buttons::isButtonPressed(sf::Vector2f click)
{
	return (m_text.getGlobalBounds().contains(click));
}