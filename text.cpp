// Text Analyzer
// Adam Khoshnaw

#include "text.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map> // built in hashmap
#include <vector>        // store map entries in a vector
#include <algorithm>     // sort vector

// Updates the word count for one file
void processFile(const std::string &filename, std::unordered_map<std::string, int> &wordCounts) {
    std::ifstream infile(filename); // open

    if (!infile) {
        std::cout << "Failed to open file.\n" << std::endl;
        return;
    }

    std::cout << "Analyzing file: " << filename << std::endl;
    
    std::string line;  // store line
    std::string word;  // store word extracted FROM line
    
    // read line by line
    while (std::getline(infile, line)) { 
        std::istringstream stream(line); // create string stream

        while (stream >> word) {
            std::string normalized = normalizeWord(word);

            if (!normalized.empty()) {
                wordCounts[normalized]++;
            }
        }
    }
    infile.close();
}

// Normalizes a single word
std::string normalizeWord(const std::string &word) {
    std::string result;

    // for (type variable : container) | iterate over each char in word
    for (char i : word) {
        if (isalnum(i)) { // isalnum() only a-z, A-Z, 0-9, no punctuation
            result += tolower(i);
        }
    }
    return result;
}

// Returns a sorted vector of the top N words from the map
std::vector<std::pair<std::string, int>> getTopWords(const std::unordered_map<std::string,int> &wordCounts, int topN) {

    std::vector<std::pair<std::string, int>> wordVector(wordCounts.begin(),wordCounts.end());

    // sort by word frequency, descending
    std::sort(wordVector.begin(), wordVector.end(), [] (const auto &a, const auto &b) {
        return a.second > b.second; // count of word a, count of word b
    });
    // more words than topN, resize vector
    if (topN < wordVector.size()) {
        wordVector.resize(topN);
    }
    return wordVector;  // return the sorted vector of top N words
}


