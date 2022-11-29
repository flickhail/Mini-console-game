#pragma once
#include "main.hpp"
#include "Creature.hpp"
#include "Player.hpp"

class Monster : public Creature
{
public:
	enum Type {
		DRAGON,
		ORC,
		SLIME,

		MAX_TYPES
	};

	struct MonsterData {
		std::string name;
		char symbol;
		int HP;
		int dmg;
		int gold;
	};


	// Useful for easy adding or changing the monsters int the game
	static MonsterData monsterData[MAX_TYPES];

	Monster(Type type);

	//				[UTILITY METHODS]

	// Creates a random 'class Monster' object, using
	// random generation of 'enum Type'
	static Monster GetRandomMonster();

	// Applies 'Creature::_Damage' to 'Player' object
	bool HitPlayer(Player &player);
};