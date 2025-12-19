// Text Analyzer
// Adam Khoshnaw

#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char* argv[]) {


    // Check if user gave file
    if (argc < 2) {
        std::cout << "No files to analyze.\n" << std::endl;
        return 1;
    }
    // Store file
    std::string file = argv[1];

    // Open file
    std::ifstream infile(file);

    if (!infile) {
        std::cout << "Failed to open file.\n";
        return 1;
    }
   
    // read one line to show it works
    std::string line;
    if (std::getline(infile, line))
        std::cout << line << std::endl;

    infile.close();


    return 0;
}
