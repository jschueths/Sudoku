#ifndef __SOLVER_H__
#define __SOLVER_H__

#include "board.h"

const int SIZE = 9;

void solve(Board &brd);
bool solve(Board &brd, int x, int y);
bool check(const Board &brd, const int i, const int j);
bool chkRow(const Board &brd, const int x, const int y);
bool chkCol(const Board &brd, const int x, const int y);
bool chkSqr(const Board &brd, const int x, const int y);

#endif

