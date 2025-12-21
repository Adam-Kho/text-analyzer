// Text Analyzer
// Adam Khoshnaw

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map> // built in hashmap
#include <vector>        // store map entries in a vector
#include <algorithm>     // sort vector
#include "text.h"

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

        processFile(argv[i], wordCounts);
    }

        /* wordCounts is map
        key = word | value = count
        Each element is a pair<stringm int>
        pair.first = the word
        pair.second = the count */
/* PRINTING EACH WORD AND COUNT | DEBUGGING |
        for (auto &pair : wordCounts) {
            std::cout << pair.first << ": " << pair.second << std::endl;
        } */
           // Call top words function
    auto topWords = getTopWords(wordCounts, 10);
    std::cout << "Top 10 words across provided file(s):\n";
    for (const auto &pair : topWords) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }

    return 0;
}


