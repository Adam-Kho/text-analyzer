// Text Analyzer
// Adam Khoshnaw

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map> // built in hashmap
#include <vector>        // store map entries in a vector
#include <algorithm>     // sort vector

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

        /* wordCounts is map
        key = word | value = count
        Each element is a pair<stringm int>
        pair.first = the word
        pair.second = the count */
        for (auto &pair : wordCounts) {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
        // .begin() -> start of map | .end() -> end of map
        infile.close();
    }
    // unordered_map cannot be sorted BUT vector can
    // copy all (word, count) pairs into a vector
    std::vector<std::pair<std::string, int>>wordVector(wordCounts.begin(), wordCounts.end());

    // Compare two word-count pairs, look only at their counts, bigger->first
    std::sort(wordVector.begin(), wordVector.end(), [](const std::pair<std::string, int>& a, 
      const std::pair<std::string, int>& b) {
        return a.second > b.second; // sort in descending order
      });

    std::cout << "\nTop 10 words across provided file(s):\n";
    for (size_t i {0}; i < 10 && i < wordVector.size(); ++i) {
        std::cout << wordVector[i].first << ": " << wordVector[i].second << std::endl;
    }

    std::cout << "\n" << std::endl;


    // PRINT file name
    //std::cout << "Analyzing file: " << file << std::endl;


    return 0;
}


