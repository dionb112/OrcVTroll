#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>

using namespace std;
class Character {
protected:
	int m_strength;
	int m_defense;
	int m_health = 10;
	std::string m_name;
	bool m_goFirst;
public:
	Character(int s = 0, int d = 0, std::string n = "") { m_strength = s; m_defense = d; m_name = n; }
	virtual void warCry() = 0;
	void retreat();
	void checkTarget();
	void die();
	void chooseAction();
	void setName(std::string n) { m_name = n; }
	void setGo(bool g) { m_goFirst = g; }
	std::string getName() { return m_name; }
	bool getGo() { return m_goFirst; }

};

class Troll : public Character {
public:
	void warCry() { cout << "DEATH TO THE ORC SCUM! " << endl; }
};

class Orc : public Character {
public: 
	void warCry() { cout << "DEATH TO THE TROLL SCUM!" << endl; }
};