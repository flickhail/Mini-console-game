#pragma once

enum {
	basicHP = 10,
	basicDMG = 1,
	basicGOLD = 0,
	basicLVL = 1,
	FIGHT = 1,
	RUN_AWAY = 2
};

class Player;
class Monster;

int getRandomNumber(int min, int max);