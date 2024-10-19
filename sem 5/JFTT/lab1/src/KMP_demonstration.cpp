#include "knuth_morris_pratt.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cout << "Poprawne użycie: FA pattern file\n";
    }

    std::string pattern = argv[1];
    std::string filepath = argv[2];
    std::string text;

    std::ifstream source_file(filepath);
    std::getline(source_file, text);
    source_file.close();

    std::vector<int> pattern_indexes = search(pattern, text);

    for (const auto &index : pattern_indexes)
    {
        std::cout << "Wzorzec występuje w pliku na indeksie: " << index << "\n";
    }

    return 0;
}