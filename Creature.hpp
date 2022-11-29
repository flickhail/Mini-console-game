#pragma once
#include <string>

class Creature
{
protected:
	std::string _Name{};
	char _Symbol{};
	int _HealthPoints{};
	int _Damage{};
	int _Gold{};

public:
	Creature() = default;
	Creature(const std::string& newName)
		: _Name{ newName }
	{}

	Creature(const std::string& newName, char newSymbol, int newHp, int newDmg, int newGold)
		: _Name(newName)
		, _Symbol(newSymbol)
		, _HealthPoints(newHp)
		, _Damage(newDmg)
		, _Gold(newGold)
	{}


	//				[GETTERS]

	std::string Name() const { return _Name; }
	char Symbol() const { return _Symbol; }
	int HP() const { return _HealthPoints; }
	int Damage() const { return _Damage; }
	int Gold() const { return _Gold; }


	//				[UTILITY METHODS]

	void ReduceHealth(int value);
	bool IsDead() const;
	void AddGold(int value);
};