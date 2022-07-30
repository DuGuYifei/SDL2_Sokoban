#pragma once
#include "Params.h"
using namespace Params;

class SomeObject
{
public:
	int x = -1, y = -1;
	int indexX = -1, indexY = -1;
	char name = BLANK;
	bool canMove = false;
	bool isMoving = false;

	int moveDir = MOVE_NOT;

	int moveDist = cellSize;

	SomeObject() {};
	SomeObject(int x, int y, bool canMove, char n);
	void MoveAuto();
};

