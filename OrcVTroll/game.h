#pragma once
#include "characters.h"
/// <summary>
/// using a struct here as it seems, currently, the best place for one as required by rubric
/// </summary>
struct LootTable
{
	int loot;
};

class Game {
private:
	LootTable lootTable;
	Character ** m_player = new Character *[10]; // pointer to pointers... An array of pointers to instances (objects) of the base class
	Character ** m_enemy = new Character *[10];
	int m_choice;
	bool m_playerDefends;
	std::string m_input;
	void naming();
	void initiative();
	void chooseAction();
	void skirmish();
	void checkRetreat();
	void userInput();
public:
	Game();
	void run();

};