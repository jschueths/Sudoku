#include <iostream>
#include "solver.h"
#include "board.h"

void solve(Board &brd)
{
	solve(brd, 0, 0);
}

bool solve(Board &brd, int x, int y)
{
	if(x == 9)
	{
		return true;
	}
	if(brd(x, y) == 0)
	{
		for(int i = 1; i <= 9; i++)
		{
			brd(x, y) = i;
			if(check(brd, x, y))
			{
				if(y == 8)
				{
					if(solve(brd, x+1, 0))
						return true;
				}
				else
				{
					if(solve(brd, x, y+1))
						return true;
				}
			}
		}
		brd(x, y) = 0;
		return false;
	}
	else
	{
		if(y == 8)
			return solve(brd, x+1, 0);
		else
			return solve(brd, x, y+1);
	}
}

bool check(const Board &brd, const int i, const int j)
{
	return chkRow(brd, i, j) && chkCol(brd, i, j) && chkSqr(brd, i, j);
}

bool chkRow(const Board &brd, const int x, const int y)
{
	for(int i = 0; i < SIZE; i++)
	{
		if(brd(x, i) == 0)
			continue;
		if(brd(x, y) == brd(x, i) && i != y)
				return false;
	}
	return true;
}

bool chkCol(const Board &brd, const int x, const int y)
{
	for(int i = 0; i < SIZE; i++)
	{
		if(brd(i, y) == 0)
			continue;
		if(brd(x, y) == brd(i, y) && i != x)
			return false;
	}
	return true;
}

bool chkSqr(const Board &brd, const int x, const int y)
{
	int mx = x / 3;
	int my = y / 3;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(brd(3 * mx + i, my + j) == 0)
				continue;
			if(3 * mx + i == x && 3 * my + j == y)
				continue;
			if(brd(3 * mx + i, 3 * my + j) == brd(x, y))
				return false;
		}
	}
	return true;
}

