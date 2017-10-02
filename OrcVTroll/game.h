#pragma once
#include "characters.h"
class Game {
private:
	Goblin goblins[5];
	Orc orcs[5];
public:
	Game();
	void run();
	/// <summary>
	/// using a struct here as it seems, currently, the best place for one as required by rubric
	/// </summary>
	struct GameFunctions
	{
		
	};
};