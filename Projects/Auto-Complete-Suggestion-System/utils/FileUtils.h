#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <string>
#include <vector>

namespace FileUtils
{
    // Reads a file line by line and return all non empty lines as a vector
    std::vector<std::string> readWordsFromFile(const std::string &filename);
}

#endif