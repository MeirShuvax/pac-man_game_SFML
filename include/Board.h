#pragma once

#include <vector>
#include "Object.h"
#include "StandingObject.h"
#include "MovingObject.h"
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <memory>
#include "InformationDisplay.h"
#include "Resources.h"
#include "Timer.h"

//The role of the board department is to manage the current stage 
//on the game board, to update it if necessary, and to call the various
//departments to perform actions


class Board
{
public:
    Board(char levelName[], int dataSaver[]);
    ~Board();
    void drowBoard();
    void readFromFile();
    sf::RenderWindow* getWindow() const;
    void setWindow(char levelName[]);
    void moveMovingObject();
    void chengeImages();
    void resetBoard(int dataSaver[]);
    void collisionManager();
    void updateInformationDisplay(int m_dataSaver[]);
    bool checkIsPakmanInjured();
    bool checkPassLevel();
    bool checkIsPakmanInDead() ;
    void updateBoard();
    void resetMovingObject();
    void createMovingObject(int dataSaver[]);
    void createStandingObject();
    std::vector <std::unique_ptr<MovingObject>> const& getVectorMoving();
        std::vector < std::unique_ptr<StandingObject>> const& getVectorStanding();
    std::unique_ptr<Gift> returnGiftType(sf::Vector2f location);
    Timer& getTimer();
    void updateData(int dataSaver[]);
    void gameOver();


private:
    std::vector <std::string> m_gameBoard;
    std::ifstream m_file;
    std::vector < std::unique_ptr<MovingObject>> m_moveingObject;
    std::vector <std::unique_ptr<StandingObject>> m_standingObject;
    sf::RenderWindow* m_window;
    InformationDisplay m_informationDisplay;
    Timer m_timer;
    sf::Sprite m_gameOver;
};