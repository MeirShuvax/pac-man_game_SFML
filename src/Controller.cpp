#include "Controller.h"
#include <SFML/Audio.hpp>
#include "Sound.h"
#include <iostream>
//===============================================
Controller::Controller() :
	m_playlist("Playlist.txt"), m_menu(), m_isExit(false)
{
	resetDataSaver();
}
//===============================================
void Controller::run()
{
	srand(time(0));
	char levelName[LINE_LEN];

	//Read data about the current game stage, and run on it
	while (!m_playlist.eof())
	{
		m_playlist.getline(levelName, LINE_LEN);
		Board board(levelName, m_dataSaver);
		if (m_dataSaver[I_LEVEL] == 1)
			m_menu.openMenu(board, m_isExit);

		runOnLevel(board);
		if (m_isExit)
			break;
	}
}
//===============================================
//Run the game, and do the necessary actions
//===============================================
void Controller::runOnLevel(Board& board)
{
	board.getTimer().resetTime();
	Resources::resources().getSound().getGameSound().setLoop(true);
	Resources::resources().getSound().getGameSound().play();

	//Run the game, as long as the window is open
	while (board.getWindow()->isOpen())
	{

		board.updateInformationDisplay(m_dataSaver);
		board.drowBoard();
		eventsManager(board);
		board.moveMovingObject();
		board.chengeImages();
		board.collisionManager();
		board.updateBoard();
		board.updateData(m_dataSaver);
		if (checkStatusChanges(board))
			break;
	}

	Resources::resources().getSound().getGameSound().stop();
}
//===============================================
//Check various events related to the window, and execute them
//===============================================
void Controller::eventsManager(Board& board)
{
	for (auto event = sf::Event{}; board.getWindow()->pollEvent(event);)
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			board.getWindow()->close();
			m_dataSaver[I_LEVEL] = 1;
			m_playlist.seekg(0, std::ios::beg);
			break;

		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
			{
				sf::Clock clock;
				clock.restart();
				m_menu.openMenu(board, m_isExit);
				board.getTimer().addTime(clock.getElapsedTime().asSeconds());
			}
			break;
		}
	}
}
//===============================================
void Controller::resetDataSaver()
{
	m_dataSaver[I_LEVEL] = 1;
	m_dataSaver[I_LIFE] = SUM_LIFE;
	m_dataSaver[I_SCORE] = SCORE;
}
//===============================================
//Check the status of the player, and take necessary actions accordingly
//===============================================
bool Controller::checkStatusChanges(Board& board)
{
	if (board.checkIsPakmanInjured())
		board.resetMovingObject();
	if (board.checkPassLevel())
	{
		m_dataSaver[I_LEVEL]++;
		return true;
	}
	if (board.checkIsPakmanInDead())
	{
		board.gameOver();
		resetDataSaver();
		m_playlist.seekg(0, std::ios::beg);
		return true;
	}
	if (board.getTimer().isEndTime())
	{
		board.resetBoard(m_dataSaver);
		board.getTimer().resetTime();
	}
	if (m_isExit)
		return true;

	return false;
}

