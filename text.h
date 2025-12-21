// Text Analyzer
// Adam Khoshnaw
// This file contains function declarations

#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map> // built in hashmap
#include <vector>        // store map entries in a vector
#include <algorithm>     // sort vector



// Updates the word count for one file
void processFile(const std::string &filename, std::unordered_map<std::string, int> &wordCounts);

// Normalizes a single word
std::string normalizeWord(const std::string &word);

// Returns a sorted vector of the top N words from the map
std::vector<std::pair<std::string, int>> getTopWords(const std::unordered_map<std::string,int> &wordCounts, int topN);

#endif


