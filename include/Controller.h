#pragma once
#include <fstream>
#include "Resources.h"
#include "Board.h"
#include "Menu.h"

//The role of the controller department is to manage the course of the game,
//and if necessary call the
//various departments to perform actions


class Controller
{
public:
	Controller();
	void run();
	void runOnLevel(Board& board); 
	void eventsManager(Board& board);
	void resetDataSaver();
	bool checkStatusChanges(Board& board);

private:
	std::ifstream m_playlist;
	Menu m_menu;
	bool m_isExit;
	int m_dataSaver[3];

};