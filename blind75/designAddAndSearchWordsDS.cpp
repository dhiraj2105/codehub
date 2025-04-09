#include <bits/stdc++.h>
using namespace std;

class WordDictionary
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

    // Helper function to perform a recursive search, used to handle '.'
    bool searchHelper(string word, int index, TrieNode *node)
    {
        if (index == word.size())
        {
            return node->isEndOfWord; // Return true if we are at the end of the word
        }

        char ch = word[index];

        if (ch == '.')
        {
            // If the current character is a dot, check all possible children
            for (TrieNode *child : node->children)
            {
                if (child != nullptr && searchHelper(word, index + 1, child))
                {
                    return true;
                }
            }
            return false;
        }
        else
        {
            int idx = ch - 'a'; // Convert character to index (e.g., 'a' -> 0, 'b' -> 1)
            if (node->children[idx] != nullptr)
            {
                return searchHelper(word, index + 1, node->children[idx]);
            }
            else
            {
                return false; // If the character doesn't exist, return false
            }
        }
    }

public:
    WordDictionary()
    {
        root = new TrieNode();
    }

    void addWord(string word)
    {
        TrieNode *current = root;

        for (char ch : word)
        {
            int index = ch - 'a';

            if (current->children[index] == nullptr)
            {
                current->children[index] = new TrieNode();
            }

            current = current->children[index];
        }

        current->isEndOfWord = true; // Mark the end of the word
    }

    bool search(string word)
    {
        return searchHelper(word, 0, root); // Start the recursive search from the root
    }
};

int main()
{
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
