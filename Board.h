#pragma once
#include "Player.h"


class Board
{
public:
	Player player;
	int boxNum = 0;
	SomeObject* map[MAP_SIZE][MAP_SIZE];
	SomeObject* targets[BOX_MAX];

	Board(int level);
	void PlayerMove(int dir);
	bool CheckStatus();
	bool CheckWin();
};

