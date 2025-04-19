#include "FileUtils.h"
#include <fstream>  // For file stream
#include <iostream> // For console printing
#include <sstream>  // For string stream

using namespace std;

// Implementation for readWordsFromFile
vector<string> FileUtils::readWordsFromFile(const string &filename)
{
    vector<string> words;    // To store all words
    ifstream file(filename); // Open the file

    // check if the file was successfully opened
    if (!file.is_open())
    {
        cerr << "Error: Could not open file " << filename << endl;
        return words; // Return empty vector if file could not be opened
    }

    string line;

    // read file line by line
    while (getline(file, line))
    {
        // ignore empty lines
        if (!line.empty())
        {
            words.push_back(line);
        }
    }
    file.close(); // Close the file
    return words; // Return the vector of words
}