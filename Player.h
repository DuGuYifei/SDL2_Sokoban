#pragma once
#include "SomeObject.h"
class Player : public SomeObject
{
public:
	Player() {};
	Player(int x, int y, bool canMove, char n);
	void Move(int dir, SomeObject* so = nullptr);
};

