#include "game.h"

Game::Game()
{
	
}

void Game::run()
{
	goblins[0].warCry();
	orcs[0].warCry();
	system("PAUSE");
}
