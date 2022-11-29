#pragma once
#include "Creature.hpp"
#include "Monster.hpp"

class Player : public Creature
{
private:
	int _level;

	//				[INITIAL VALUES]

	static constexpr int _basicLVL{ 1 };
	static constexpr int _basicHP{ 10 };
	static constexpr int _basicDMG{ 1 };
	static constexpr int _basicGOLD{ 0 };

public:
	enum class FightState
	{
		Fight = 1,
		RunAway = 2,

		Undefined
	};

	Player(std::string& name)
		: Creature(name, '@', _basicHP, _basicDMG, _basicGOLD)
		, _level(_basicLVL)
	{}


	//				[GETTERS]

	int Level() const { return _level; }
	void Stats() const;


	//				[UTILITY METHODS]

	void LevelUp() { _level++; _Damage++; }
	FightState Encounter(const Monster &monster);

	// Handles the fight mechanics.
	// Return 'true' if monster is killed, false otherwise
	bool Fight(Monster &monster, bool &OUT_gameOverState);

	// Handles the escape mechanic, when you can escape the fight with some luck
	// returns 'true' if you escaped, false otherwise
	bool RunAway(Monster &monster, bool &OUT_gameOverState);

	bool HasWon() const { return (_level >= 20) ? true : false; }
	void HasLost();
};