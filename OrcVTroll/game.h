#pragma once
#include "characters.h"
/// <summary>
/// using a struct here as it seems, currently, the best place for one as required by rubric
/// </summary>
struct GameStates
{
	//start , combat etc
};
class Game {
private:
	Character ** m_trolls = new Character *[10]; // pointer to pointers... An array of pointers to instances (objects) of the base class
	Character ** m_orcs = new Character *[10];
	int m_choice;
	std::string m_input;
	std::string m_team;
	void naming();
	void initiative();
	void battle();
	void resetGame();
	void checkDmg();
	void userInput();
public:
	Game();
	void run();

};