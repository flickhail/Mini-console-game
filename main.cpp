#include "main.hpp"
#include "Player.hpp"
#include "Monster.hpp"

#include <iostream>
#include <string>
#include <algorithm>


// Name validation. Handles 3 cases:
// 1. string is empty
// 2. string consists of spaces only
// 3. string is too long to fit the charactersCount
// [TODO] more cases?
bool NameValidation(const std::string& name, size_t charactersCount)
{
	if (name.empty())
	{
		std::cout << "\nThe name is empty\n";
		return false;
	}

	if (name.length() > charactersCount)
	{
		std::cout << "\nThe name is too long, it must be " << charactersCount << " characters\n";
		return false;
	}

	auto isSpace = [](char symbol) -> bool
	{
		if (symbol == ' ' || symbol == '\t')
			return true;

		return false;
	};

	if (std::ranges::all_of(name, isSpace))
	{
		std::cout << "\nThe name consists only of spaces\n";
		return false;
	}

	return true;
}

// Removes the leading and trailing white spaces from a string
std::string StringTruncate(const std::string& string)
{
	// temporary string for truncation process of leading and trailing white spaces
	std::string truncationServant{};

	// Removing the leading space characters
	{
		std::istringstream nameTruncationStream{ string };
		nameTruncationStream >> std::ws;
		std::getline(nameTruncationStream, truncationServant);
	}

	// Removing the trailing space characters
	{
		//												reverse the character order in string
		std::istringstream nameTruncationStream{ std::string{ truncationServant.rbegin(), truncationServant.rend() } };
		nameTruncationStream >> std::ws;
		std::getline(nameTruncationStream, truncationServant);
	}

	// reverse back to normal
	return { truncationServant.rbegin(), truncationServant.rend() };
}

// Returns the playerName from user input (terminal)
// std::string implements move construction, so there is no overhead in returning by value
std::string GetPlayerName(size_t charactersCount)
{
	std::string name{};

	std::cout << "Welcome, stranger!\n";

	bool isValid{ false };
	do
	{
		std::cout << "Enter your name: ";
		std::getline(std::cin, name);

		name.shrink_to_fit();
		
		isValid = NameValidation(name, charactersCount);

		if (!isValid)
		{
			std::cout << "Player name is invalid, try again\n\n";
			name.erase();
		}

	} while (!isValid);

	name = StringTruncate(name);

	return name;
}

// Entry point
int main()
{
	// Limitation of the string size is for consistency of user interface
	// too long string leads to bad-looking interface
	constexpr int playerNameMAXSIZE{ 25 };

	std::string playerName;
	playerName.reserve(playerNameMAXSIZE);

	playerName = GetPlayerName(playerNameMAXSIZE);

	Player player(playerName);

	// Controls the main game loop.
	bool exitCondition{ false };
	while (!exitCondition)
	{
		Monster monster{ Monster::GetRandomMonster() };
		
		Player::FightState playerInput{ Player::FightState::Undefined };

		// Controls the fight loop
		bool battleFinished{ false };
		while (!battleFinished && !exitCondition)
		{
			player.Stats();
			playerInput = player.Encounter(monster);
			switch (playerInput)
			{
			case Player::FightState::Fight:
				battleFinished = player.Fight(monster, exitCondition);
				break;

			case Player::FightState::RunAway:
				battleFinished = player.RunAway(monster, exitCondition);
				break;
			}
		}

		if (player.Level() > 20) {
			std::cout << "\nCongratulation, " << playerName << "! You've become the true hero...\n";
			exitCondition = true;
		}
	}
	return 0;
}