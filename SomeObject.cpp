#include "SomeObject.h"

SomeObject::SomeObject(int x, int y, bool canMove, char n) :indexX(x), indexY(y), canMove(canMove), name(n) 
{
	this->x = y * cellSize;
	this->y = x * cellSize;
};

void SomeObject::MoveAuto()
{
	if (moveDist == cellSize)
	{
		isMoving = false;
		moveDir = MOVE_NOT;
	}

	if (!canMove || !isMoving)
		return;

	switch (moveDir)
	{
	case MOVE_NOT:
		return;
	case MOVE_LEFT:
		x -= moveSpeed;
		break;
	case MOVE_DOWN:
		y += moveSpeed;
		break;
	case MOVE_RIGHT:
		x += moveSpeed;
		break;
	case MOVE_UP:
		y -= moveSpeed;
		break;
	default:
		break;
	}

	moveDist += moveSpeed;
}