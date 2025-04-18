#include "Trie.h"

// constructor for TrieNode
TrieNode::TrieNode()
{
    // initialize this node as not being the end of word
    isEndOfWord = false;
}
// constructor for Trie
Trie::Trie()
{
    // initialize the root node
    root = new TrieNode();
}

// inserts a word into Trie
void Trie::insert(const string &word)
{
    TrieNode *current = root;

    for (char ch : word)
    {
        // if current character is not already a child node
        if (current->children.find(ch) == current->children.end())
        {
            // create a new node for this character
            current->children[ch] = new TrieNode();
        }
        // move to the child node
        current = current->children[ch];
    }
    // mark the end of the word
    current->isEndOfWord = true;
}

// helper function to collect all words starting from a given trie node
void Trie::collectAllWords(TrieNode *node, string prefix, vector<string> &results)
{
    // if currect node is end of word , add it to results
    if (node->isEndOfWord)
    {
        results.push_back(prefix);
    }
    // iterate over all children of current node
    for (auto &pair : node->children)
    {
        char nextChar = pair.first;
        TrieNode *nextNode = pair.second;
        // recursively collect all words starting from the child node
        collectAllWords(nextNode, prefix + nextChar, results);
    }
}

vector<string> Trie::getSuggestions(const string &prefix)
{
    TrieNode *current = root;
    for (char ch : prefix)
    {
        if (current->children.find(ch) == current->children.end())
        {
            return {};
        }
        current = current->children[ch];
    }
    vector<string> results;
    collectAllWords(current, prefix, results);
    return results;
}