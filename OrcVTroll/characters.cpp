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

void Character::chooseAction()
{

	//enemy actions
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
