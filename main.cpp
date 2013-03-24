#include <iostream>
#include <fstream>
#include "solver.h"
#include "board.h"

int main(int argc, char * argv[]) {
	Board brd;
	std::fstream in;
	in.open(argv[1]);
	if(in.is_open())
	{
		in >> brd;
	}
	else
	{
		std::cerr << "Unable to open file for reading" << std::endl;
		return 1;
	}
	std::cout << "Solving..." << std::endl;
	solve(brd);
	std::cout << "Ok" << std::endl;
	std::ofstream out;
	out.open(argv[2]);
	out << brd;
	std::cout << brd;
	return 0;
}

