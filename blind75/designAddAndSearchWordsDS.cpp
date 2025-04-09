#include <bits/stdc++.h>
using namespace std;

class WordDictionary
{
private:
    // Structure to represent each node in the Trie
    struct TrieNode
    {
        TrieNode *children[26]; // Array to store child nodes for each letter (a-z)
        bool isEndOfWord;       // Flag to indicate if this node represents the end of a word

        // Constructor to initialize a TrieNode
        TrieNode() : isEndOfWord(false)
        {
            // Initialize all 26 child nodes as nullptr
            fill(begin(children), end(children), nullptr);
        }
    };

    TrieNode *root; // Root of the Trie, starting point for all operations

    // Helper function for recursive searching (used to handle '.')
    bool searchHelper(string word, int index, TrieNode *node)
    {
        // Base case: If we have reached the end of the word
        if (index == word.size())
        {
            // Return true if this node marks the end of a word
            return node->isEndOfWord;
        }

        // Get the current character to check
        char ch = word[index];

        // Case 1: If the current character is a dot ('.'), we need to check all children nodes
        if (ch == '.')
        {
            // Loop through all possible children nodes (a-z)
            for (TrieNode *child : node->children)
            {
                // If the child exists and the recursive search for the rest of the word succeeds
                if (child != nullptr && searchHelper(word, index + 1, child))
                {
                    return true; // Return true if any child node matches the rest of the word
                }
            }
            return false; // Return false if no child node matches the rest of the word
        }
        else
        {
            // Case 2: If the current character is not a dot, find the corresponding child node
            int idx = ch - 'a'; // Convert character to index (e.g., 'a' -> 0, 'b' -> 1, etc.)

            // If the corresponding child node exists, continue searching
            if (node->children[idx] != nullptr)
            {
                return searchHelper(word, index + 1, node->children[idx]); // Recursively search for the next character
            }
            else
            {
                return false; // Return false if no child node exists for the character
            }
        }
    }

public:
    // Constructor to initialize the WordDictionary object
    WordDictionary()
    {
        root = new TrieNode(); // Create a new TrieNode as the root
    }

    // Function to add a word to the Trie
    void addWord(string word)
    {
        TrieNode *current = root; // Start from the root node

        // Loop through every character of the word
        for (char ch : word)
        {
            int index = ch - 'a'; // Convert the character to its corresponding index (0 for 'a', 1 for 'b', etc.)

            // If the current character's node doesn't exist, create it
            if (current->children[index] == nullptr)
            {
                current->children[index] = new TrieNode(); // Create a new node for this character
            }

            // Move to the next child node (continue with the next character)
            current = current->children[index];
        }

        current->isEndOfWord = true; // Mark the node as the end of the word after inserting all characters
    }

    // Function to search for a word in the Trie
    bool search(string word)
    {
        return searchHelper(word, 0, root); // Start the recursive search from the root node
    }
};

int main()
{
    // Create a new WordDictionary object
    WordDictionary *obj = new WordDictionary();

    // Add some words to the dictionary
    obj->addWord("bad");
    obj->addWord("dad");
    obj->addWord("mad");

    // Search for various words and print the results
    cout << obj->search("pad") << endl; // Should return 0 (false) because "pad" was not added
    cout << obj->search("bad") << endl; // Should return 1 (true) because "bad" was added
    cout << obj->search(".ad") << endl; // Should return 1 (true) because ".ad" matches "bad", "dad", "mad"
    cout << obj->search("b..") << endl; // Should return 1 (true) because "b.." matches "bad"

    return 0;
}
