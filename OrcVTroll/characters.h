#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <Windows.h>
#include <cstdlib>

using namespace std;
class Character {
protected:
	int m_meleeOffense;
	int m_meleeDefense;
	int m_magicOffense;
	int m_magicDefense;
	int m_health = 10;
	std::string m_name;
	bool m_readyToGo;
public:
	Character(int t_meO = 0,
			  int t_meD = 0,
			  int t_maO = 0,
			  int t_maD = 0,
			  std::string t_n = "");
	void retreat();
	void checkTarget();
	void die();
	void chooseAction(bool playerDef);
	void setName(std::string t_n) { m_name = t_n; }
	void setGo();
	std::string getName() { return m_name; }
	bool getGo() { return m_readyToGo; }
	void setStats(	int t_meO, 
					int t_meD, 
					int t_maO, 
					int t_maD) 
	{	m_meleeOffense = t_meO; 
		m_meleeDefense = t_meD; 
		m_magicOffense = t_maO; 
		m_magicDefense = t_maD; }
	
	virtual void warCry() = 0;
	virtual void team() = 0;
};

class Troll : public Character {
public:
	void warCry() { cout << "DEATH TO THE ORC SCUM! " << endl; }
	void team() { cout << "Troll"; }
	//different attacks can also be unique for polymorphism
};

class Orc : public Character {
public: 
	void warCry() { cout << "DEATH TO THE TROLL SCUM!" << endl; }
	void team() { cout << "Orc"; }

};