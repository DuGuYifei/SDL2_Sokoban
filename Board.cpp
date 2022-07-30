#include "Board.h"
#include "stdio.h"

Board::Board(int level)
{
	if (level < 1 || level > 5)
		return;

	//--------------------------------------
	for (int i = 0; i < MAP_SIZE; i++)
		for (int j = 0; j < MAP_SIZE; j++)
		{
			map[i][j] = nullptr;
		}

	int r = 0;
	int c = 0;
	FILE* f = fopen(mapfile[level-1], "r");
	char text[12];
	while (fgets(text, 1024, f) != NULL)
	{
		while(c < 11)
		{
			switch (text[c])
			{
			case BLANK:
				map[r][c] = nullptr;
				break;
			case WALL:
				map[r][c] = new SomeObject(r, c, false, WALL);
				break;
			case PLAYER:
				player = Player(r, c, true, PLAYER);
				map[r][c] = &player;
				break;
			case BOX:
				map[r][c] = new SomeObject(r, c, true, BOX);
				break;
			case TARGET:
				targets[boxNum] = new SomeObject(r, c, false, TARGET);
				boxNum++;
				break;
			default:
				c = 12;
				break;
			}
			c++;
		}
		c = 0;
		r++;
	}
	fclose(f);
}

void Board::PlayerMove(int dir)
{
	int targetX = player.indexX;
	int targetY = player.indexY;
	SomeObject* box = nullptr;
	switch (dir)
	{
	case MOVE_UP:

		targetX--;

		if (map[targetX][targetY])
		{
			if (map[targetX][targetY]->name == WALL)
				break;

			if (map[targetX - 1][targetY])
				break;

			box = map[targetX][targetY];
			map[targetX][targetY]->indexX--;
			map[targetX - 1][targetY] = map[targetX][targetY];
		}

		map[targetX][targetY] = &player;
		map[player.indexX][player.indexY] = nullptr;

		player.indexX--;

		player.Move(MOVE_UP, box);

		break;

	case MOVE_RIGHT:
		targetY++;

		if (map[targetX][targetY])
		{
			if (map[targetX][targetY]->name == WALL)
				break;

			if (map[targetX][targetY + 1])
				break;

			box = map[targetX][targetY];
			map[targetX][targetY]->indexY++;
			map[targetX][targetY + 1] = map[targetX][targetY];
		}

		map[targetX][targetY] = &player;
		map[player.indexX][player.indexY] = nullptr;

		player.indexY++;

		player.Move(MOVE_RIGHT, box);

		break;

	case MOVE_DOWN:
		targetX++;

		if (map[targetX][targetY])
		{
			if (map[targetX][targetY]->name == WALL)
				break;

			if (map[targetX + 1][targetY])
				break;

			box = map[targetX][targetY];
			map[targetX][targetY]->indexX++;
			map[targetX + 1][targetY] = map[targetX][targetY];

		}

		map[targetX][targetY] = &player;
		map[player.indexX][player.indexY] = nullptr;

		player.indexX++;

		player.Move(MOVE_DOWN, box);

		break;
	case MOVE_LEFT:
		targetY--;

		if (map[targetX][targetY])
		{
			if (map[targetX][targetY]->name == WALL)
				break;

			if (map[targetX][targetY - 1])
				break;

			box = map[targetX][targetY];
			map[targetX][targetY]->indexY--;
			map[targetX][targetY - 1] = map[targetX][targetY];
		}

		map[targetX][targetY] = &player;
		map[player.indexX][player.indexY] = nullptr;
		player.indexY--;

		player.Move(MOVE_LEFT, box);

		break;
	default:
		break;
	}
}

bool Board::CheckWin()
{
	for (int i = 0; i < boxNum; i++)
	{
		int ix = targets[i]->indexX;
		int iy = targets[i]->indexY;
		if (!map[ix][iy] || map[ix][iy]->name != BOX)
		{
			return false;
		}
	}
	return true;
}

bool Board::CheckStatus()
{
	for(int i = 0; i < MAP_SIZE;i++)
		for (int j = 0; j < MAP_SIZE; j++)
		{
			if (!map[i][j])
				continue;

			map[i][j]->MoveAuto();
		}

	if (player.isMoving)
	{
		return false;
	}

	return CheckWin();

}