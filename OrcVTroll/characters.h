#pragma once
#include <iostream>
using namespace std;
class Character {
protected:
	int m_strength;
	int m_defense;
	int m_health = 10;
public:
	void setValues(int s, int d) { m_strength = s; m_defense = d; }
	//virtual void die() = 0;

};

class Goblin : public Character {
public:
	void warCry() { cout << " DIE, ORC SCUM! " << endl; }
};

class Orc : public Character {
public:
	void warCry() { cout << " DIE, GOBLIN SCUM!" << endl; }
};