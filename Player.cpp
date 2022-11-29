#include "Player.hpp"
#include "main.hpp"

#include <iostream>
#include <format>

// Prints the player stats
void Player::Stats() const
{
	std::cout << "\nYou have " << HP() << " HP, " << Gold() << " gold, " << Level() << " LVL, " << Damage() << " damage.\n";
}

// Validates the input string using the rule:
// 1. input must be 1 character
// 2. input is an integer value
// 3. integer value can be correctly casted to 'enum FightState'
bool FightInputValidation(const std::string& input)
{
	if (input.length() > 1)
	{
		std::cout << "Incorrect input (too many characters)\n";
		return false;
	}

	// For easy converting the 'string' to 'int'
	std::istringstream integerValidationStream{ input };

	int value;
	integerValidationStream >> value;
	if (integerValidationStream.fail())
	{
		std::cout << "Incorrect input (it's not a number)\n";
		return false;
	}

	if (value != 1 && value != 2)
	{
		std::cout << "Incorrect input (incorrect number)\n";
		return false;
	}

	return true;
}

// Returns the player input that guaranteed to be the correct FightState value
Player::FightState GetFightInput(const std::string& inputPromt)
{
	std::string input{};
	bool validInput{ false };
	do
	{
		std::cout << inputPromt;

		std::getline(std::cin, input);

		input.shrink_to_fit();

		validInput = FightInputValidation(input);

	} while (!validInput);

	std::istringstream intConverterStream{ input };

	// After validation it is completely safe to cast input to enum
	int value;
	intConverterStream >> value;
	return static_cast<Player::FightState>(value);
}

// Prints info about monster encountered and gathers the player input
Player::FightState Player::Encounter(const Monster &monster)
{
	const std::string infoMsg{ std::format("You encountered with: {}({}HP, {}dmg, {}gold)\n\n",
								monster.Name(), monster.HP(), monster.Damage(), monster.Gold()) };

	const std::string inputPromtMsg{ "1.Fight\n2.Run away\n>: " };

	std::cout << infoMsg;

	FightState state{ GetFightInput(inputPromtMsg) };

	return state;
}

// Handles the fight mechanics.
// Returns 'true' if monster is killed, false otherwise
bool Player::Fight(Monster &monster, bool &OUT_isPlayerDead)
{
	bool monsterKilled{ false };

	std::cout << "\nYou've attacked " << monster.Name() << "!\n";
	monster.ReduceHealth(_Damage);

	if (monster.IsDead()) {
		std::cout << monster.Name() << " was defeated. You earn: " << monster.Gold() << " gold. ";
		std::cout << "level up!\n";

		AddGold(monster.Gold());
		LevelUp();

		OUT_isPlayerDead = false;
		monsterKilled = true;
	}
	else
	{
		OUT_isPlayerDead = monster.HitPlayer(*this);
		monsterKilled = false;
	}

	return monsterKilled;
}

// Handles the escape mechanic, when you can escape the fight with some luck
// Returns 'true' if you escaped, false otherwise
bool Player::RunAway(Monster &monster, bool &OUT_isPlayerDead)
{
	// 80% chance to escape
	constexpr float escapeChance{ 0.8f };
	constexpr int minRandomVal{ 0 };
	constexpr int maxRandomVal{ 10 };
	constexpr float escapeThreshold{ (maxRandomVal - minRandomVal) * escapeChance + minRandomVal};

	bool isEscaped{ false };

	float value{ GetRandomNumber<float>(minRandomVal, maxRandomVal) };
	if (value < escapeThreshold)
	{
		std::cout << "\nYou escaped!\n";

		OUT_isPlayerDead = false;

		isEscaped = true;
	}
	else
	{
		std::cout << "\nYou failed to escape...\n";

		OUT_isPlayerDead = monster.HitPlayer(*this);
		isEscaped = false;
	}

	return isEscaped;
}

// GameOver info
void Player::HasLost()
{
	std::cout << "\nYou died.\n";
}