#include <iostream>
#include "Monster.h"
#include "main.h"

bool Monster::defined = false;

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
	{ "dragon", 'D', 20, 4, 100 },
	{ "orc", 'o', 4, 2, 25 },
	{ "slime", 's', 1, 1, 10 }
};

Monster::Monster(Type a_type)
	: Creature(monsterData[a_type].name, monsterData[a_type].symbol, monsterData[a_type].HP, monsterData[a_type].dmg, monsterData[a_type].gold)
{
	defined = true;
}

Monster Monster::getRandomMonster()
{
	return static_cast<Type>(getRandomNumber(0, MAX_TYPES - 1));
}

void Monster::hit(Player &p)
{
	std::cout << "\n" << getName() << " attacks you! ";
	p.reduceHealth(damage);
	std::cout << "(you have " << p.getHP() << "hp)\n";
	if (p.isDead()) {
		p.hasLost();
	}
}