#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Player.h"
#include "Monster.h"

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int main()
{
	int choice;
	bool exit_condition = false;
	std::string player_name;
	std::cout << "Welcome, stranger!\n" << "Please, enter your name: ";
	std::getline(std::cin, player_name);
	Player player(player_name);
	srand(static_cast<unsigned int>(time(0)));
	rand();

	while (!exit_condition) {
		player.getStats();
		Monster m = Monster::getRandomMonster();
		bool fight_condition = false;
		while (!fight_condition) {
			choice = player.Encounter(m);
			switch (choice) {
			case FIGHT:
				fight_condition = player.fight(m);
				break;
			case RUN_AWAY:
				fight_condition = player.run_away(m);
				break;
			}
		}
		if (player.getLVL() > 20) {
			std::cout << "\nCongratulation! You've become the true hero...\n";
			exit_condition = true;
		}
	}
	return 0;
}