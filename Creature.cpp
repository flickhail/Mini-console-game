#include <iostream>
#include "Creature.h"

void Creature::reduceHealth(int value)
{
	healthPoints -= value;
}

bool Creature::isDead() 
{
	return (healthPoints <= 0) ? true : false;
}

void Creature::addGold(int value)
{
	gold += value;
}