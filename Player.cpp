#include <iostream>
#include <cstdlib>
#include "Player.h"
#include "Monster.h"

void Player::getStats()
{
	std::cout << "\nYou have " << getHP() << " HP, " << getGold() << " gold, " << getLVL() << " LVL, " << getDamage() << " damage.\n";
}

int Player::Encounter(Monster &m)
{
	int choice;
	std::cout << "You encountered with: " << m.getName() << " (" << m.getHP() << "HP, " << m.getDamage() << "dmg, " << m.getGold() << "g)\n";
	std::cout << "1.Fight\n" << "2.Run away\n";
	std::cin >> choice;
	return choice;
}

bool Player::fight(Monster &m)
{
	std::cout << "\nYou've attacked " << m.getName() << "!\n";
	m.reduceHealth(damage);
	if (m.isDead()) {
		std::cout << m.getName() << " was defeated. You earn: " << m.getGold() << " gold. ";
		std::cout << "level up!\n";
		addGold(m.getGold());
		lvlUp();
		return true;
	}
	else {
		std::cout << m.getName() << " has " << m.getHP() << "hp.\n";
		m.hit(*this);
		return false;
	}
}

bool Player::run_away(Monster &m)
{
	int value = getRandomNumber(0, 10);
	if (value >= 5) {
		std::cout << "\nYou escaped!\n";
		return true;
	}
	else {
		std::cout << "\nYou failed to escape...\n";
		m.hit(*this);
		return false;
	}
}

void Player::hasLost()
{
	std::cout << "You died.\n";
	exit(0);
}