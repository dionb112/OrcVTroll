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
	Goblin goblins[5];
	Orc orcs[5];

	void initiative(); //for combat
	void resetGame();
	void checkDmg();
public:
	Game();
	void run();

};