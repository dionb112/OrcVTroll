#include "game.h"

Game::Game()
{

}

///Simple function which is providing complete user validation for entered values (avoids infinite while loops)
void Game::userInput()
{
	while (!false)
	{
		std::getline(std::cin, m_input);
		std::stringstream myStream(m_input);
		if (myStream >> m_choice)
			break;
		std::cout << "Invalid entry, please try again" << std::endl;
	}
}
void Game::naming()
{
	std::string name;
	system("CLS");
	std::cout << "You have 10 " << m_team << "s at your disposal for this battle." << std::endl;
	for (int i = 0; i < 10; i++)
	{
		m_orcs[i]->setName(std::string  { "Orc   Grunt " + std::to_string(i + 1) }); // deafult name if chose not to name
		m_trolls[i]->setName(std::string{ "Troll Grunt " + std::to_string(i + 1) }); // Just naming the enemies as you would see them in war.. numbered enemies !!

		std::cout << "Would you like to name your warriors?\n1:Yes\n2:No" << std::endl;
		userInput();
		if (m_choice == 1)
		{
			std::cout << "Please name " << m_team << " number " << i + 1 << "." << std::endl;
			std::cin >> name;
			if (m_team == "Orc")
			{
				m_orcs[i]->setName(name);

			}
			else
			{
				m_trolls[i]->setName(name);
			}
		}
	}
}

///function which rolls initiative for each character, lining up each 10 with the opposite 10 and checking who will act first on each side
///it's easiest for now to assume each character will fight with the character on the opposing side with the same array index.
///Later there may be some functionality whereby characters reassign who they are fighting when their opponent dies ! 
void Game::initiative()
{
	int trollRoll;
	int orcRoll;
	std::cout << "Rolling Battle Initiative (order) for each character: " << endl;

	for (int i = 0; i < 10; i++)
	{
		trollRoll = 0;
		orcRoll = 0;
		while (trollRoll == orcRoll)
		{
			trollRoll = rand() % 20;
			orcRoll = rand() % 20;
			if (trollRoll < orcRoll)
			{
					m_orcs[i]->setGo(true);
					m_trolls[i]->setGo(false);
					std::cout << m_orcs[i]->getName() << " gets to act before " << m_trolls[i]->getName();
			}
			else
			{
				m_orcs[i]->setGo(false);
				m_trolls[i]->setGo(true);
				std::cout << m_trolls[i]->getName() << " gets to act before " << m_orcs[i]->getName();
			}
		}
		std::cout << endl;
	}
}

void Game::battle()
{
	for (int i = 0; i < 10; i++)
	{
		if (m_orcs[i]->getGo())
		{
			//chose action if enemy, provide options if player
		}
	}
}

void Game::run()
{
	srand(time(NULL)); //set the seed
	for (int i = 0; i < 10; i++)
	{
		m_trolls[i] = new Troll;
		m_orcs[i] = new Orc;
	}
	while (m_choice < 1 || m_choice > 2)
	{
		system("CLS");
		std::cout << "Choose a side to battle for control of the Kingdom!\n1:Orcs\n2:Trolls" << std::endl;
		userInput();
		switch (m_choice)
		{
		case 1:
			system("CLS");
			m_orcs[0]->warCry(); //just using the first indexed troll and orc objects to do the first war cry ! 
			m_team = "Orc";
			break;
		case 2:
			system("CLS");
			m_trolls[0]->warCry();
			m_team = "Troll";
			break;
		}
	}

	///for now these can be here
	naming();
	initiative();
	battle();

	std::cout << endl;
	system("PAUSE");
}
