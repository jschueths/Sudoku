#include "board.h"

Board::Board(){}

Board::Board(const Board &src)
{
	if(this != &src)
		copy(src);
}

Board::~Board(){}

const Board& Board::operator=(const Board& src)
{
	if(this != &src)
		copy(src);
	return *this;
}

const int& Board::operator()(const int x, const int y) const
{
	return m_data[x][y];
}

int& Board::operator()(const int x, const int y)
{
	return m_data[x][y];
}

void Board::copy(const Board &src)
{
	for(size_t i = 0; i < M_SIZE; i++)
		for(size_t j = 0; j < M_SIZE; j++)
			m_data[i][j] = src.m_data[i][j];
	return;
}

std::ostream& operator<<(std::ostream &out, const Board &brd)
{
	for(int i = 0; i < M_SIZE; i++)
	{
		for(int j = 0; j < M_SIZE; j++)
		{
			out << brd.m_data[i][j];
			if(j != M_SIZE - 1)
				out << " ";
		}
		out << std::endl;
	}
	return out;
}

std::istream& operator>>(std::istream &in, Board &brd)
{
	for(int i = 0; i < M_SIZE; i++)
	{
		for(int j = 0; j < M_SIZE; j++)
		{
			in >> brd.m_data[i][j];
		}
	}
	return in;
}
