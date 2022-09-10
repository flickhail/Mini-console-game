#pragma once
#include <string>

class Creature
{
protected:
	std::string name;
	char symbol;
	int healthPoints;
	int damage;
	int gold;
public:
	Creature(std::string a_name, char a_symbol, int hp, int dmg, int a_gold) 
		:name(a_name), symbol(a_symbol), healthPoints(hp), damage(dmg), gold(a_gold) {}

	std::string getName() { return name; }
	char getSymbol() { return symbol; }
	int getHP() { return healthPoints; }
	int getDamage() { return damage; }
	int getGold() { return gold; }

	void reduceHealth(int value);
	bool isDead();
	void addGold(int value);
};