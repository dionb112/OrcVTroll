#include "characters.h"

//void Character::die()
//{
//	if (m_health <= 0)
//	{
//		//die
//	}
//}

Character::Character(int t_meO, int t_meD, int t_maO, int t_maD, std::string t_n) 
	: m_readyToGo{false}
{
	m_meleeOffense = t_meO;
	m_meleeDefense = t_meD;
	m_magicOffense = t_maO;
	m_magicDefense = t_maD;
	m_name = t_n;
}

/// <summary>
/// So the idea here is that if the player has chosen a defensive action then the corresponding enemy will ALWAYS choose a random offensive one.
/// I wanted it setup like this so we would never have a situation where two characters go to fight each other and both tries to defend (BORING).
/// And so then, if the player has chosen an offensive action the AI can choose ANY action, so we now have a (close to) random chance that they block,
/// and also a chance that BOTH characters charge at each other with an attack (EXCITING).
/// </summary>
/// <param name="playerDef"></param>
void Character::chooseAction(bool playerDef)
{
	int randomAction;
	if (playerDef)
	{
		randomAction = rand() % 12; // total ammount of offensive actions
	}
	else
	{
		randomAction = rand() % 15; //total number of offensive + defensive actions
	}
	switch (randomAction)
	{
	//MELEE
	case 1:
			   //meO, meD, maO, maD (For now all actions stats are same for player and enemy to keep it BALANCED)
		setStats(2,   6,   0,   0);
		break;
	case 2:
		setStats(3, 5, 0, 0);
		break;
	case 3:
		setStats(4, 4, 0, 0);
		break;
	case 4:
		setStats(5, 3, 0, 0);
		break;
	case 5:
		setStats(6, 2, 0, 0);
		break;
	case 6:
		setStats(8, 1, 0, 0);
		break;
	case 7:
		setStats(10, 0, 0, 0);
		break;
	//MAGIC
	case 8:
		setStats(0, 0, 2, 6);
		break;
	case 9:
		setStats(0, 0, 3, 5);
		break;
	case 10:
		setStats(0, 0, 6, 3);
		break;
	case 11:
		setStats(0, 0, 8, 2);
		break;
	case 12:
		setStats(0, 0, 10, 0);
		break;
	//DEFEND
	case 13:
		setStats(0, 10, 0, 0);
		break;
	case 14:
		setStats(0, 0, 0, 10);
		break;
	case 15:
		setStats(0, 5, 0, 5);
		break;
}

void Character::setGo()
{
	if (m_readyToGo)
	{
		m_readyToGo = false;
	}
	else
	{
		m_readyToGo = true;
	}
}
