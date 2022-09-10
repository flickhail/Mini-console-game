#pragma once
#include "main.h"
#include "Creature.h"
#include "Player.h"

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

	static MonsterData monsterData[MAX_TYPES];
	static bool defined;

	Monster(Type a_type);

	static Monster getRandomMonster();
	void hit(Player &p);
};