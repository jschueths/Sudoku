module;

import stl;

export module board;

const int M_SIZE = 9;
export class Board;

export std::ostream& operator<<(std::ostream &out, const Board &brd);
export std::istream& operator>>(std::istream &in, Board &brd);
using size_t = std::size_t;
export class Board
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
