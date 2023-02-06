#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <Board.h>
//An abstract class that assigns to each button
//in the menu
//And the different functions for each button realized by virtual
class Buttons
{
public:
    Buttons(const char buttonName[], sf::Vector2f Location);
    virtual ~Buttons() = default;
    void setText(sf::Vector2f Location);
    void setRectangle();
    void drowButton(sf::RenderWindow& menuWindow);
     bool isButtonPressed(sf::Vector2f click) ;
    //A function responsible for highlighting as open the cursor on it
    void highlightsButton(sf::ConvexShape& m_arrow);
    void resetHighlightsButton();
    virtual void turnOnButton(sf::RenderWindow& menuWindow, Board& board, bool& isExit) = 0;
    bool isPressedNow();

protected:
    sf::Text m_text;
    sf::Color m_color;
    sf::Color m_defaultColor;
    sf::RectangleShape m_rectangle;
    bool m_pressedNow;
};