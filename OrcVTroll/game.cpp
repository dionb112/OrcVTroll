#include "game.h"

Game::Game() : m_playerDefends{ false }
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

void Game::run()
{
	srand(time(NULL)); //set the seed
	m_choice = 0;

	while (m_choice < 1 || m_choice > 2)
	{
		system("CLS");
		std::cout << "Choose a side to battle for control of the Kingdom!\n1:Orcs\n2:Trolls" << std::endl;
		userInput();
	}
	switch (m_choice)
	{
	case 1:
		system("CLS");
		for (int i = 0; i < 10; i++)
		{
			m_enemy[i] = new Troll;
			m_player[i] = new Orc;
		}
		break;
	case 2:
		system("CLS");
		for (int i = 0; i < 10; i++)
		{
			m_player[i] = new Troll;
			m_enemy[i] = new Orc;
		}
		break;
	}
	m_player[0]->warCry(); //just using the first indexed troll and orc objects to do the first war cry ! 
	naming();
	initiative();
	std::cout << endl;
	system("PAUSE");
	chooseAction();//needs to run through twice, first for the quick grunts
	chooseAction();//then followed by the slow ones#
	std::cout << endl;
	system("PAUSE");
	skirmish();
	checkRetreat();
}
void Game::naming()
{
	std::string name;
	system("CLS");
	m_choice = 0;
	while (m_choice < 1 || m_choice > 2)
	{
		system("CLS");
		cout << "So...You are a War Chief, in command of 10 ";
		m_player[0]->team();//Displays character type ( Orc or Troll )
		cout <<" Grunts" << endl;
		std::cout << "Would you like to name your warriors?\n1:Yes\n2:No" << std::endl;
		userInput();
	}
	for (int i = 0; i < 10; i++)
	{
		m_player[i]->setName(std::string  { "Orc Grunt " + std::to_string(i + 1) }); // deafult name if chose not to name
		m_enemy[i]->setName(std::string { "Troll Grunt " + std::to_string(i + 1) }); // Just naming the enemies as you would see them in war.. numbered enemies !!

		if (m_choice == 1)
		{
			system("CLS");
			std::cout << "Please name ";
			m_player[0]->team();//again just using 0 to call text functions
			std::cout << " number " << i + 1 << "." << std::endl;
			std::cin >> name;
			m_player[i]->setName(name);
		}
	}
}

///function which rolls initiative for each character, lining up each 10 with the opposite 10 and checking who will act first on each side
///it's easiest for now to assume each character will fight with the character on the opposing side with the same array index.
///Later there may be some functionality whereby characters reassign who they are fighting when their opponent dies ! 
void Game::initiative()
{
	int playerRoll;
	int enemyRoll;
	system("CLS");
	std::cout << "Rolling Battle Initiative (order) for each character: " << endl;
	for (int i = 0; i < 10; i++)
	{
		playerRoll = 0;
		enemyRoll = 0;
		while (playerRoll == enemyRoll)
		{
			playerRoll = rand() % 20;
			enemyRoll = rand() % 20;
			if (playerRoll > enemyRoll)
			{
				m_player[i]->setGo(); // sets the player bool of go first to on (will always be off before it get to here)
				std::cout << m_player[i]->getName() << " gets to act before " << m_enemy[i]->getName();
			}
			else if (enemyRoll > playerRoll) // seems redundant but if it's equal it won't notice until end of this loops iteration ends
			{
				std::cout << m_enemy[i]->getName() << " gets to act before " << m_player[i]->getName();
			}
		}
		std::cout << endl << endl;
	}
}

void Game::chooseAction()
{
	for (int i = 0; i < 10; i++)
	{
		//chose action if enemy, provide options if player, send 0 for enemy, 1 for player
		if (m_player[i]->getGo())
		{
			m_choice = 0;
			while (m_choice < 1 || m_choice > 2)
			{
				system("CLS");
				std::cout << "Choose an action for: " << m_player[i]->getName() << ". \n1: Offensive\n2: Defensive" << std::endl;
				userInput();
			}
			if (m_choice == 1) //offense
			{
				m_playerDefends = false;
				m_choice = 0;
				while (m_choice < 1 || m_choice > 2)
				{
					system("CLS");
					std::cout << "Choose an offense type.\n1: Melee\n2: Magic" << std::endl;
					userInput();
				}
				if (m_choice == 1) //Melee
				{
					m_choice = 0;
					while (m_choice < 1 || m_choice > 7)
					{
						system("CLS");
						std::cout << "Choose a MELEE attack.\n1: Careful Strike\n2: Sweeping Strike\n3: Slashing Strike\n4: Lunging Strike\n5: Pierching Strike\n6: Roll and Slice\n7: FRENZIED STRIKE" << std::endl;
						userInput();
					}
					// unique melee styles which provide more or less Melee Offense and Defensive
					switch (m_choice)
					{
					case 1:
						//					meO, meD, maO, maD
						m_player[i]->setStats(2, 6, 0, 0);
						break;
					case 2:
						m_player[i]->setStats(3, 5, 0, 0);
						break;
					case 3:
						m_player[i]->setStats(4, 4, 0, 0);
						break;
					case 4:
						m_player[i]->setStats(5, 3, 0, 0);
						break;
					case 5:
						m_player[i]->setStats(6, 2, 0, 0);
						break;
					case 6:
						m_player[i]->setStats(8, 1, 0, 0);
						break;
					case 7:
						m_player[i]->setStats(10, 0, 0, 0);
						break;
					}
				}
				else //Magic !!!!!!!!
				{
					m_choice = 0;
					while (m_choice < 1 || m_choice > 5)
					{
						system("CLS");
						std::cout << "Choose a MAGIC spell.\n1: Air Blast\n2: Earth Blast\n3: Fire Blast\n4: Water Blast\n5: DEATH BLAST" << std::endl;
						userInput();
					}
					// unique Magic styles which provide more or less Melee Offense and Defensive
					switch (m_choice)
					{
					case 1:
						//					meO, meD, maO, maD
						m_player[i]->setStats(0, 0, 2, 6);
						break;
					case 2:
						m_player[i]->setStats(0, 0, 3, 5);
						break;
					case 3:
						m_player[i]->setStats(0, 0, 6, 3);
						break;
					case 4:
						m_player[i]->setStats(0, 0, 8, 2);
						break;
					case 5:
						m_player[i]->setStats(0, 0, 10, 0);
						break;
					}
				}
			}
			else // DEFENSE
			{
				m_playerDefends = true;
				m_choice = 0;
				while (m_choice < 1 || m_choice > 3)
				{
					system("CLS");
					std::cout << "Choose a DEFENSIVE maneuver.\n1: Protect against MELEE\n2: Protect against MAGIC\n3: 50/50 split protect." << std::endl;
					userInput();
				}
				// unique melee styles which provide more or less Melee Offense and Defensive
				switch (m_choice)
				{
				case 1:
					//					meO, meD, maO, maD  ....   GAME BALANCE IS FUN !
					m_player[i]->setStats(0, 10, 0, 0);
					break;
				case 2:
					m_player[i]->setStats(0, 0, 0, 10);
					break;
				case 3:
					m_player[i]->setStats(0, 5, 0, 5);
					break;
				}
			}
		}
		else
		{
			system("CLS");
			std::cout << m_enemy[i]->getName() << " is choosing his action";
			for (int i = 0; i < 3; i++)
			{
				Sleep(250);
				std::cout << ".";
			}
			std::cout << endl;
			m_enemy[i]->randomAction(m_playerDefends); // If player defending -> attack, else do ANY random action (becuase, both defendng = BORING, both Attacking = INTENSE, mix = EXPECED)
		}
		// so that readyToGo bool is swapped to whatever it wasn't, will then call battle() again so that the opponent or player, as required can take their go
		// this bool will be then be ser again at next initiative (i,e battle() runs through twice, for the grunts who go first and then the corresponding get to go)
		m_player[i]->setGo();
	}
}

/// Function here which compares all the stat values which have previously been set
/// Checks which characters take damage then reduces their health by that ammount if so
/// Finally checks if a character health reaches 0, kill them
void Game::skirmish()
{
	int dmg = 0;
	int pDamage = 0;
	int eDamage = 0;
	system("CLS");
	cout << "CHARGE";
	for (int i = 0; i < 4; i++)
	{
		Sleep(500);
		std::cout << "!";
	}
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		dmg = m_player[i]->getMeO() - m_enemy[i]->getMeD(); // storing this value here so can see if damage happened
		if ( dmg > 0 )
		{
			eDamage = dmg;//if so then store that damage 
		}

		dmg = m_enemy[i]->getMeO() - m_player[i]->getMeD();
		if ( dmg > 0)
		{
			pDamage = dmg;
		}

		dmg = m_player[i]->getMaO() - m_enemy[i]->getMaD();
		if ( dmg > 0)
		{
			eDamage = dmg;
		}

		dmg = m_enemy[i]->getMaO() - m_player[i]->getMaD();
		if ( dmg > 0)
		{
			pDamage = dmg;
		}
		///checking if damaged
		if (pDamage != 0)
		{
			m_player[i]->takeDamage(pDamage);
			cout << m_player[i]->getName() << " has taken " << pDamage << " damage!" << endl;
			///checking if dead
			if (m_player[i]->getHealth() <= 0)
			{
				m_player[i]->die();
			}
			cout << endl;
		}
		if (eDamage != 0)
		{
			m_enemy[i]->takeDamage(eDamage); //finally that apply stored dmg and output a message
			cout << m_enemy[i]->getName() << " has taken " << eDamage << " damage!" << endl;

			if (m_enemy[i]->getHealth() <= 0)
			{
				m_enemy[i]->die();
				///loot table implementation
				cout << m_player[i]->getName() << " decides to loot " << m_enemy[i]->getName() << "s corpse!" << endl;
				std::cout << endl;
				system("PAUSE");
				int randLoot = rand() % 4;
				switch (randLoot)
				{
				case 1:
					cout << "Oh look at the ";
					m_enemy[i]->team();
					cout << " Chainmail!";
					break;
				case 2:
					cout << "Oh look at the ";
					m_enemy[i]->team();
					cout << " Necklace!";
					break;
				case 3:
					cout << "Oh look at the";
					m_enemy[i]->team();
					cout << " Scimitar!";
					break;
				case 4:
					cout << "You found nothing interesting";
					break;
				}
				cout << endl;
			}
			cout << endl;
		}
		dmg = 0;
		pDamage = 0;
		eDamage = 0;
	}
}

void Game::checkRetreat()
{
	short playerCount = 0;
	short enemyCount = 0;
	for (int i = 0; i < 10; i++)
	{
		if (m_player[i]->getHealth() > 0)
		{
			playerCount++;
		}
		if (m_enemy[i]->getHealth() > 0)
		{
			enemyCount++;
		}
	}
	if (playerCount == 0)
	{
		cout << "You have lost all your grunts, unlucky!" << endl;
	}
	if (enemyCount == 0)
	{
		cout << "You have slaughtered ALL enemy grunts, CONGRATULATIONS!" << endl;
	}
	if (enemyCount == 0 && playerCount == 0)
	{
		cout << "Both sides have lost all the grunts, novody wins, HA!" << endl;
	}
	// I had decided if the ratio was 3:1 (or worse) player grunts to enemies they would surrender this math calculates those odds
	//but since i am removing the potential for multiple combat rounds it matters not
	else if (playerCount > enemyCount) 
	{
		cout << "WOW! It looks like your forces outnumber the enemies!" << endl;
		m_enemy[0]->team();
		cout << "s may not be THE brightest, but they seem to still value their survival when the odds are against them!" << endl;
		cout << "So, the enemy has retreated, you have WON the battle! CONGRATULATIONS!";
	}
	else if (enemyCount > playerCount)
	{
		cout << "WOW! It looks like the enemy forces outnumber your own!" << endl;
		m_player[0]->team();
		cout << "s are not the bravest, they seem to still value their survival over victory!" << endl;
		cout << "So, against your wishes your grunts have retreated, better luck next time !";

	}
	else
	{
		cout << "Looks like a draw... how BORING, try again!"; // when I add multiple comabt rounds back in this won't happen of course :)
	}
	std::cout << endl;
	system("PAUSE");
}
