#pragma once
#include "main.h"
#include "Creature.h"
#include "Monster.h"

class Player : public Creature
{
private:
	int level;
public:
	Player(std::string name) : Creature(name, '@', basicHP, basicDMG, basicGOLD), level(basicLVL) {}

	int getLVL() { return level; }

	void lvlUp() { level++; damage++; }
	bool hasWon() { return (level >= 20) ? true : false; }
	void getStats();
	int Encounter(Monster &m);
	bool fight(Monster &m);
	bool run_away(Monster &m);
	void hasLost();
};