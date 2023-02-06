#include "Board.h"
#include <sstream>
#include "Define.h"
#include "Bricks.h"
#include "Cookies.h"
#include "Demons.h"
#include "Door.h"
#include "Gift.h"
#include "Key.h"
#include "Pakman.h"
#include "GiftSuperPakman.h"
#include "GiftAddLife.h" 
#include "GiftAddTime.h"
#include "GiftFreezeDemon.h"
#include <Windows.h>
//===============================================
Board::Board(char levelName[] , int dataSaver[]) :
	m_file(levelName), m_informationDisplay(), m_timer()
{
	if (m_file.fail())
		std::cerr << "Error";

	setWindow(levelName);
	readFromFile();
	resetBoard(dataSaver);
}
//===============================================
Board::~Board()
{
	delete m_window;
}
//===============================================
// drow the board game, incloude the Information
// Display 
//===============================================
void Board::drowBoard()
{
	m_window->clear();

	for (int cell = 0; cell < m_standingObject.size(); ++cell)
		m_standingObject[cell]->drowObject(m_window);

	for (int cell = 0; cell < m_moveingObject.size(); ++cell)
		m_moveingObject[cell]->drowObject(m_window);

	m_informationDisplay.showInformationDisplay(m_window);

	m_window->display();
}
//===============================================
void Board::readFromFile()
{
	std::string line;
	while (!m_file.eof())
	{
		getline(m_file, line);
		m_gameBoard.push_back(line);
	}
}
//===============================================
sf::RenderWindow* Board::getWindow() const
{
	return m_window;
}
//===============================================
// set the window size by the now level txt
//===============================================
void Board::setWindow(char levelName[])
{
	std::string line;
	std::getline(m_file, line);
	sf::Vector2f m_windowSize;

	auto issNumbers = std::istringstream(line);
	issNumbers >> m_windowSize.y;
	issNumbers >> m_windowSize.x;

	m_window = new sf::RenderWindow(sf::VideoMode((m_windowSize.x * PIXEL_SIZE),
		(m_windowSize.y * PIXEL_SIZE + INFORMATION_DISPLAY)), levelName);
}
//===============================================
//Move the moving objects, the Pacman according to its type,
//and the demons by having them receive the Pacman's position 
//and run to it
//===============================================
void Board::moveMovingObject()
{
	sf::Vector2f pakmanLocation;

	for (int i = 0; i < m_moveingObject.size(); ++i)
	{
		auto pakman = dynamic_cast<Pakman*>(&(*(m_moveingObject[i])));
		if (pakman)
			pakmanLocation = pakman->getLocation();
	}

	for (int cell = 0; cell < m_moveingObject.size(); ++cell)
		m_moveingObject[cell]->makeMove(m_window->getSize(), pakmanLocation);
}
//===============================================
void Board::chengeImages()
{
	for (int cell = 0; cell < m_moveingObject.size(); ++cell)
		m_moveingObject[cell]->chengeImage();
}
//===============================================
void Board::resetBoard(int dataSaver[])
{
	createMovingObject(dataSaver);
	createStandingObject();
}
//===============================================
//create the Moving Object by update his vector
//===============================================
void Board::createMovingObject(int dataSaver[])
{
	m_moveingObject.clear();

	for (int row = 0; row < (m_window->getSize().y - INFORMATION_DISPLAY) / PIXEL_SIZE; ++row)
		for (int col = 0; col < m_window->getSize().x / PIXEL_SIZE; ++col)
			switch (m_gameBoard[row][col])
			{
			case PAKMAN:
				m_moveingObject.push_back(std::make_unique<Pakman>(sf::Vector2f(col, row), dataSaver));
				break;

			case DEMON:
				int kind = (rand() % 3) + 1;
				m_moveingObject.push_back(std::make_unique<Demons>(sf::Vector2f(col, row), kind));
				break;
			}
}
//===============================================
//create the Moving Object by update his vector
//===============================================
void Board::createStandingObject()
{
	m_standingObject.clear();

	for (int row = 0; row < (m_window->getSize().y - INFORMATION_DISPLAY) / PIXEL_SIZE; ++row)
		for (int col = 0; col < m_window->getSize().x / PIXEL_SIZE; ++col)
			switch (m_gameBoard[row][col])
			{
			case	BRICK :
				m_standingObject.push_back(std::make_unique<Bricks>(sf::Vector2f(col, row)));	break;

			case	COOKIE:
				m_standingObject.push_back(std::make_unique<Cookies>(sf::Vector2f(col, row)));	break;
				
			case	DOOR:
				m_standingObject.push_back(std::make_unique<Door>(sf::Vector2f(col, row)));	break;

			case	GIFT:
				m_standingObject.push_back(returnGiftType(sf::Vector2f(col, row)));	break;
			
			case	KEY:
				m_standingObject.push_back(std::make_unique<Key>(sf::Vector2f(col, row))); 	break;
			}
}
//===============================================
//Check for conflicts between the various objects, and take the required action
//===============================================
void Board::collisionManager()
{
	for (int i = 0; i < m_moveingObject.size(); ++i)
		for (int j = 0; j < m_standingObject.size(); ++j)
			if (m_moveingObject[i]->collidesWith(*m_standingObject[j]))
				m_moveingObject[i]->handleCollision(*m_standingObject[j], *this);

	for (int i = 0; i < m_moveingObject.size(); ++i)
		for (int j = i + 1; j < m_moveingObject.size(); ++j)
			if (m_moveingObject[i]->collidesWith(*m_moveingObject[j]))
				m_moveingObject[i]->handleCollision(*m_moveingObject[j], *this);
}
//===============================================
void Board::updateInformationDisplay(int m_dataSaver[])
{
	m_informationDisplay.updateScore(m_dataSaver[I_SCORE]);
	m_informationDisplay.updateLife(m_dataSaver[I_LIFE]);
	m_informationDisplay.updateTime(m_timer.countingDown());
	m_informationDisplay.updateLevel(m_dataSaver[I_LEVEL]);
}
//===============================================
bool Board::checkIsPakmanInjured()
{
	for (int i = 0; i < m_moveingObject.size(); ++i)
		if (m_moveingObject[i]->isInjured())
			return true;
	return false;
}
//================================================
bool Board::checkPassLevel()
{
	for (int i = 0; i < m_standingObject.size(); ++i)
	{
		auto cookie = dynamic_cast<Cookies*>(&(*(m_standingObject[i])));
		if (cookie)
			return false;
	}
	return true;
}
//================================================
bool Board::checkIsPakmanInDead()
{
	for (int i = 0; i < m_moveingObject.size(); ++i)
		if (m_moveingObject[i]->isDead())
			return true;
	return false;
}
//================================================
// delete the dead objects
//================================================
void Board::updateBoard()
{
	std::erase_if(m_standingObject, [](const auto& item)
		{
			return item->isDead();
		});
}
//================================================
void Board::resetMovingObject()
{
	for (int i = 0; i < m_moveingObject.size(); ++i)
		m_moveingObject[i]->resetTofirstLocation();
}
//================================================
std::vector <std::unique_ptr<StandingObject>> const& Board::getVectorStanding()
{
	return m_standingObject;
}
//================================================
std::vector <std::unique_ptr<MovingObject>> const& Board::getVectorMoving()
{
	return m_moveingObject;
}
//================================================
// gift raffle
//================================================
std::unique_ptr<Gift> Board::returnGiftType(sf::Vector2f location)
{
	int loto = rand() % 4;

	switch (loto)
	{
	case ADD_TIME:
		return std::make_unique<GiftAddTime>(location);

	case ADD_LIFE:
		return std::make_unique<GiftAddLife>(location);

	case FREEZE_DEMON:
		return std::make_unique<GiftFreezeDemon>(location);

	case SUPER_PAKMAN:
		return std::make_unique<GiftSuperPakman>(location);
	}
}
//================================================
Timer& Board::getTimer()
{
	return m_timer;
}
//================================================
//update the array Data
//================================================
void Board::updateData(int dataSaver[])
{
	for (int i = 0; i < m_moveingObject.size(); ++i)
		if (m_moveingObject[i]->getLife() != EMPTY)
		{
			dataSaver[I_SCORE] = m_moveingObject[i]->getScore();
			dataSaver[I_LIFE] = m_moveingObject[i]->getLife();
			break;
		}
}
//================================================
//drow game over
//================================================
void Board::gameOver()
{
	m_gameOver.setTexture(Resources::resources().getImages().getGameOverTexture());
	m_gameOver.setScale(sf::Vector2f(m_window->getSize().x/ m_gameOver.getGlobalBounds().width,
		m_window->getSize().y/ m_gameOver.getGlobalBounds().height));
	m_window->clear();
	m_window->draw(m_gameOver);
	m_window->display();
	Sleep(5000);
}