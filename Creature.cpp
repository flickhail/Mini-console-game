#include "Creature.hpp"

#include <iostream>

// Reduces the health of this creature
void Creature::ReduceHealth(int value)
{
	_HealthPoints -= value;
}

// Checks whether the creature is dead or not
bool Creature::IsDead() const
{
	return (_HealthPoints <= 0) ? true : false;
}

// Adds gold to the creature
void Creature::AddGold(int value)
{
	_Gold += value;
}