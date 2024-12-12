module;

#include <array>
#include <cstring>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

export module stl;

export namespace std {
    using std::cout;
    using std::cin;
    using std::cerr;
    using std::flush;
    using std::endl;
    using std::ostream;
    using std::istream;
    using std::fstream;
    using std::ifstream;
    using std::ofstream;
    using std::operator<<;

    using std::string;
    using std::vector;
    using std::unordered_map;
    using std::map;

    using std::strcmp;

    using std::size_t;
}

