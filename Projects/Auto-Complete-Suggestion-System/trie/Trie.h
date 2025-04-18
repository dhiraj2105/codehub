#ifndef TRIE_H
#define TRIE_H

#include <unordered_map> // For storing child nodes
#include <string>        // For string operations
#include <vector>        // To return multiple suggestions

using namespace std;

// TrieNode represents each node in Trie
class TrieNode
{
public:
    // Child nodes are stored in an unordered map, each node can have multiple children ( a - z )
    unordered_map<char, TrieNode *> children;
    // Flag that shows if a word is completed or not , if True - completed
    bool isEndOfWord;
    // Constructor to initialize the node
    TrieNode();
};

// Trie class that manages insertion and suggestions
class Trie
{
private:
    TrieNode *root;

    // Helper function to recursively collect all words from given node
    void collectAllWords(TrieNode *node, string prefix, vector<string> &results);

public:
    // Constructor to initialize the root node of Trie
    Trie();

    // insert a word into trie
    void insert(const string &word);

    // Get word suggestions for a given prefix
    vector<string> getSuggestions(const string &prefix);
};

#endif