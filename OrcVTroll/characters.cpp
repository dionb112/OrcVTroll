#include "characters.h"

//void Character::die()
//{
//	if (m_health <= 0)
//	{
//		//die
//	}
//}

Character::Character(int t_meO, int t_meD, int t_maO, int t_maD, std::string t_n)
	: m_readyToGo{ false }, m_health(10)
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
void Character::randomAction(bool playerDef)
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
		setStats(1, 7, 0, 0);
		break;
	case 2:
		setStats(2, 5, 0, 0);
		break;
	case 3:
		setStats(3, 4, 0, 0);
		break;
	case 4:
		setStats(6, 1, 0, 0);
		break;
	case 5:
		setStats(6, 3, 0, 0);
		break;
	case 6:
		setStats(8, 2, 0, 0);
		break;
	case 7:
		setStats(11, 0, 0, 0);
		break;
		//MAGIC
	case 8:
		setStats(0, 0, 1, 7);
		break;
	case 9:
		setStats(0, 0, 2, 5);
		break;
	case 10:
		setStats(0, 0, 6, 2);
		break;
	case 11:
		setStats(0, 0, 7, 3);
		break;
	case 12:
		setStats(0, 0, 11, 0);
		break;
		//DEFEND
	case 13:
		setStats(0, 11, 0, 0);
		break;
	case 14:
		setStats(0, 0, 0, 11);
		break;
	case 15:
		setStats(0, 4, 0, 6); // just to make it unique
		break;
	}
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

void Character::setStats(int t_meO, int t_meD, int t_maO, int t_maD)
{
	m_meleeOffense = t_meO;
	m_meleeDefense = t_meD;
	m_magicOffense = t_maO;
	m_magicDefense = t_maD;
}