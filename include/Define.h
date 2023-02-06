#pragma once

const int LINE_LEN = 11;
const int PIXEL_SIZE = 40;
const int MENU_WIDTH = 715;
const int MENU_HEIGHT = 900;
const int INFORMATION_DISPLAY = PIXEL_SIZE * 1.5;
const int SUPER_TIME = 20;
const int FREEZE_TIME = 20;
const float SIZE_MOVINGS = 0.8;
const int EMPTY = -1;
const int GIFT_ADD_TIME = 120;
const char HELP_TEXT[] = "HLPE:\nPac-Man is a game, where the player\ncontrols the titular character through\na maze, eating points and avoiding\nghosts. The player moves Pac-Man\nthrough the maze using the arrow keys.\nPac - Man's goal is to eat all the dots in\nthe maze while avoiding the ghosts.\nIn addition, each cookie received\nearns the Pacman points.\nIf Pac-Man touches a ghost, he loses a\nlife. The game ends when the player loses\nall lives or completes the final level.\nLife number : 3\nNumber of steps : 3\nTo stop the game and return\n to the menu press esc ";
const int SUM_LIFE = 3;
const int SCORE = 0;


enum TypeObject
{
	BRICK = '#',
	COOKIE = '*',
	DEMON = '&',
	DOOR = 'D',
	GIFT = '$',
	KEY = '%',
	PAKMAN = 'a',
};

enum GiftType
{
	ADD_TIME,
	ADD_LIFE,
	FREEZE_DEMON,
	SUPER_PAKMAN,
};

enum demoneType
{
	FREEZE_DEMONS,
	SLOW_DEMONE,
	MEDIUM_DEMONE,
	FAST_DEMONE,
};

enum dataSaverIndex
{
	I_LEVEL,
	I_LIFE,
	I_SCORE,
};
