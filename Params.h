#pragma once
#define BLANK ' '
#define PLAYER '!'
#define BOX '@'
#define WALL '#'
#define TARGET '$'

namespace Params
{
	constexpr int cellSize = 45;
	constexpr int moveSpeed = 1;
	constexpr int MAP_SIZE = 10;
	constexpr int BOX_MAX = 5;
	constexpr int adjustDistanceX = 140;
	constexpr int adjustDistanceY = 63;
	constexpr char mapfile[5][9]{ "map1.txt","map2.txt","map3.txt","map4.txt","map5.txt" };

	enum Direction{
		MOVE_NOT = 0,
		MOVE_LEFT = 1,
		MOVE_UP = 2,
		MOVE_RIGHT = 3,
		MOVE_DOWN = 4
	};

};
