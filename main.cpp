// Text Analyzer
// Adam Khoshnaw

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>

int main(int argc, char* argv[]) {


    // Check if user gave file
    if (argc < 2) {
        std::cout << "No files to analyze.\n" << std::endl;
        return 1;
    }
    // LIKE Key = std:string & Value = int
    std::unordered_map<std::string, int> wordCounts;
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
                //std::cout << word << std::endl;
                std::string normalized;
                // for (type variable : container)
                for (char i : word) {
                    if (isalnum(i)) {
                        normalized += tolower(i);
                    }
                }
                if (!normalized.empty()) {
                    wordCounts[normalized]++;
                }
            }
        }
        for (auto &pair : wordCounts) {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
        std::cout << "\n" << std::endl;

        infile.close();
    }

    // PRINT file name
    //std::cout << "Analyzing file: " << file << std::endl;


    return 0;
}
