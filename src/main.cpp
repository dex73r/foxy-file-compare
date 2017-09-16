#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

// return 1 = bad arugment count
// return 2 = file(s) not found
int main(int argc, char **argv)
{
    if (argc != 3)
        return 1;
    std::ifstream fsOriginal(argv[1], std::ios::binary);
    std::ifstream fsSuspect(argv[2], std::ios::binary);
    if (!fsOriginal || !fsSuspect)
        return 2;
    std::vector<unsigned char> original, suspect;
    unsigned char input;
    while (fsOriginal >> std::hex >> input)
        original.push_back(input);
    while (fsSuspect >> std::hex >> input)
        suspect.push_back(input);
    int min = original.size();
    std::cout << min << "\n";
    if (suspect.size() < min)
        min = suspect.size();

    std::cout << min << "\n";
    for (int i = 0; i < min; ++i)
    {
        unsigned char o, s;
        o = original.at(i);
        s = suspect.at(i);
        if (o != s)
            continue;

        std::cout << std::hex << std::setw(8) << i << ": "
                  << "s=" << std::setw(2) << (int)s << " - o:"
                  << std::setw(2) << (int)o << '\n';
    }
    return 0;
}