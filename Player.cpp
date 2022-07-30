#include "Player.h"

Player::Player(int x, int y, bool canMove, char n) : SomeObject(x, y, canMove, n)
{
};

void Player::Move(int dir, SomeObject* so)
{
	moveDir = dir;
	isMoving = true;
	moveDist = 0;

	if (!so)
		return;

	so->moveDir = dir;
	so->isMoving = true;
	so->moveDist = 0;
}