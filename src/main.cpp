import stl;
import solver;
import board;

bool parseArgs(const int argc, char * argv[], std::string &input, std::string &output);
void usage(std::string call);

int main(int argc, char * argv[])
{
	if(argc < 3 || argc > 5)
	{
		usage(argv[0]);
		return 1;
	}
	Board brd;
	std::string input = "";
	std::string output = "";
	std::fstream in;
	if(!parseArgs(argc, argv, input, output))
	{
		usage(argv[0]);
		return 1;
	}
	in.open(input.c_str());
	if(in.is_open())
	{
		in >> brd;
		in.close();
	}
	else
	{
		std::cerr << "Unable to open file for reading: " << input << std::endl;
		return 1;
	}
	std::cout << "Original:" << std::endl;
	std::cout << brd << std::endl;
	solve(brd);
	std::cout << "Solved:" << std::endl;
	std::cout << brd << std::endl;
	if(!output.empty())
	{
		std::ofstream out;
		out.open(output.c_str());
		if(out.is_open())
		{
			out << brd;
			out.close();
		}
		else
		{
			std::cerr << "Unable to open file for writing: " << output << std::endl;
			return 1;
		}
	}
	return 0;
}

void usage(std::string call)
{
	std::cerr << "Solve a sudoku puzzle" << std::endl << std::endl;
	std::cerr << "Usage:" << std::endl;
	std::cerr << "\t" << call << " -i <input_file> [-o <output_file>]" << std::endl;
	std::cerr << std::endl;
	return;
}

bool parseArgs(const int argc, char *argv[], std::string &input, std::string &output)
{
	for(int i = 1; i < argc; i++)
	{
		if(std::strcmp(argv[i], "-i") == 0)
		{
			if(i + 1 != argc)
				input = argv[++i];
			else
				return false;
			continue;
		}
		if(std::strcmp(argv[i], "-o") == 0)
		{
			if(i + 1 != argc)
				output = argv[++i];
			else
				return false;
			continue;
		}
		return false;
	}
	return true;
}
