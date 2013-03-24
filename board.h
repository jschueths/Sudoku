#ifndef __BOARD_H__
#define __BOARD_H__
#include <iostream>
#include <fstream>

const int M_SIZE = 9;
class Board;

std::ostream& operator<<(std::ostream &out, const Board &brd);
std::istream& operator>>(std::istream &in, Board &brd);

class Board
{
	public:
		Board();
		Board(const Board &src);
		~Board();
		const Board& operator=(const Board &src);
		const int& operator()(const int x, const int y) const;
		int& operator()(const int x, const int y);
		void print() const;
		friend std::ostream& operator<<(std::ostream &out, const Board &brd);
		friend std::istream& operator>>(std::istream &in, Board &brd);

	private:
		int m_data[M_SIZE][M_SIZE];
		void copy(const Board &src);
};

#endif

