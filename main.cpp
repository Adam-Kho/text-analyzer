// Text Analyzer
// Adam Khoshnaw

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main(int argc, char* argv[]) {


    // Check if user gave file
    if (argc < 2) {
        std::cout << "No files to analyze.\n" << std::endl;
        return 1;
    }
    // Store file
    for (int i {1}; i < argc; ++i) {
        std::string file = argv[i];

        // Open file
        std::ifstream infile(file);

        if (!infile) {
            std::cout << "Failed to open file.\n" << std::endl;
            return 1;
        }
       
        /* read one line to show it works
        std::string line;
        if (std::getline(infile, line))
            std::cout << line << std::endl;
        */
        // read all lines in loop

        std::cout << "Analyzing file: " << file << std::endl;
        
        std::string line;
        std::string word;

        while (std::getline(infile, line)) { 
            std::istringstream stream(line);
            while (stream >> word) {
                std::cout << word << std::endl;
            }
        }
        std::cout << "\n" << std::endl;

        infile.close();
    }

    // PRINT file name
    //std::cout << "Analyzing file: " << file << std::endl;


    return 0;
}
