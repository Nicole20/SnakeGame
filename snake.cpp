#include "stdafx.h"
#include "snake.h"

snake::snake()
{
	srand(time(NULL));

	tail.push_back(54);
	move = rand() % 4;

	switch (move)
	{
	case 0:
		move = 10;
		break;
	case 1:
		move = -10;
		break;
	case 2:
		move = 1;
		break;
	case 3:
		move = -1;
		break;
	default:
		break;
	}

	add();
}

void snake::add()
{
	egg = rand() % 100;
	for (int i = 0; i < tail.size(); i++)
	{
		if (tail[i] == egg)
		{
			egg = rand() % 100;
			i = 0;
		}
	}
}

bool snake::check()
{
	for (int i = 0; i < tail.size() - 1; i++)
	{
		if (tail[i] == tail.back())
		{
			return 0;
		}
	}
	return 1;
}

snake::~snake()
{
}
