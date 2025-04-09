#include <bits/stdc++.h>
using namespace std;

class WordDictonary
{
private:
    struct TrieNode
    {
        TrieNode *children[26]; // For 'a' to 'z'
        bool isEndOfWord;

        TrieNode() : isEndOfWord(false)
        {
            // Initialize all children as null
            fill(begin(children), end(children), nullptr);
        }
    };

    TrieNode *root;

public:
    WordDictonary()
    {
        root = new TrieNode();
    }

    void addWord(string word)
    {
        TrieNode *current = root; // Start from the root node

        // Loop through every character of the word
        for (char ch : word)
        {
            int index = ch - 'a'; // Convert char to index (e.g., 'c' - 'a' = 2)

            // If the current character's node doesn't exist, create it
            if (current->children[index] == nullptr)
            {
                current->children[index] = new TrieNode(); // Make a new node
            }

            // Move to the child node for next character
            current = current->children[index];
        }

        // After inserting all characters, mark the end node as "end of word"
        current->isEndOfWord = true;
    }

    bool search(string word)
    {
        TrieNode *current = root; // Start at root

        for (char ch : word)
        {
            int index = ch - 'a'; // Get index for this character

            // If node for this character doesn't exist, word doesn't exist
            if (current->children[index] == nullptr)
            {
                return false;
            }

            // Move to next character node
            current = current->children[index];
        }

        // Word is present only if current node is marked as end of a word
        return current->isEndOfWord;
    }
};

int main()
{
    /*
    Design a data structure that supports adding new words and finding if a string matches any previously added string.

    Implement the WordDictionary class:

    WordDictionary() Initializes the object.
    void addWord(word) Adds word to the data structure, it can be matched later.
    bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
    */

    WordDictionary *obj = new WordDictionary();

    obj->addWord("bad");
    obj->addWord("dad");
    obj->addWord("mad");

    cout << obj->search("pad") << endl; // Should return 0 (false)
    cout << obj->search("bad") << endl; // Should return 1 (true)
    cout << obj->search(".ad") << endl; // Should return 1 (true)
    cout << obj->search("b..") << endl; // Should return 1 (true)

      return 0;
}