#include "Monster.hpp"
#include "main.hpp"

#include <iostream>

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
	{ "Dragon", 'D', 20, 4, 100 },
	{ "Orc", 'o', 4, 2, 25 },
	{ "Slime", 's', 1, 1, 10 }
};

Monster::Monster(Type monsterType)
	: Creature(monsterData[monsterType].name, monsterData[monsterType].symbol, monsterData[monsterType].HP, monsterData[monsterType].dmg, monsterData[monsterType].gold)
{}

// Gets a random monster from global monster data
Monster Monster::GetRandomMonster()
{
	return { static_cast<Type>(GetRandomNumber(0, MAX_TYPES - 1)) };
}

// Applies 'Monster::_Damage' to 'Player::_HealthPoints'
// returns 'true' if player is dead, false otherwise
bool Monster::HitPlayer(Player &player)
{
	std::cout << "\n" << Name() << " attacks you!\n";
	player.ReduceHealth(_Damage);

	if (player.IsDead())
	{
		player.HasLost();
		return true;
	}

	return false;
}