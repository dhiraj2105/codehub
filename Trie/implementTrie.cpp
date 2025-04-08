#include <bits/stdc++.h>
using namespace std;

// A Trie is a tree - like data structure used to store a dynamic set of strings, where each node represents a character of a string.

/*
Each node represents a character.

Root node is empty or null and doesn't hold any character.

Each path from root to a node represents a prefix.

Each node may have up to 26 children (if dealing with lowercase a-z).

End of a word is marked with a boolean flag, like isEndOfWord = true.
*/

// ==============================================
// A single node of the Trie (represents one character)
// ==============================================
class TrieNode
{
public:
    TrieNode *children[26]; // Array to hold references to next 26 lowercase letters
    bool isEndOfWord;       // True if the node marks the end of a word

    // Constructor for TrieNode
    TrieNode()
    {
        isEndOfWord = false; // By default, this node is NOT end of any word

        // Initialize all children to nullptr initially
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }
};

// ==============================================
// Trie class: manages all Trie operations
// ==============================================
class Trie
{
private:
    TrieNode *root; // The root node of the Trie (doesn't hold any character itself)

public:
    // Constructor
    Trie()
    {
        root = new TrieNode(); // Create an empty root node
    }

    // ====================================================
    // Insert a word into the Trie
    // e.g., "apple" → inserts a path a → p → p → l → e
    // ====================================================
    void insert(string word)
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

    // ====================================================
    // Search for a full word in the Trie
    // e.g., search("apple") → true if "apple" was inserted
    // ====================================================
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

    // ====================================================
    // Check if there is any word that starts with given prefix
    // e.g., startsWith("app") → true if "apple" or "app" was inserted
    // ====================================================
    bool startsWith(string prefix)
    {
        TrieNode *current = root; // Start at root

        for (char ch : prefix)
        {
            int index = ch - 'a'; // Get index for this character

            // If path breaks, the prefix is not in the Trie
            if (current->children[index] == nullptr)
            {
                return false;
            }

            // Move to the next node
            current = current->children[index];
        }

        // If we successfully traversed all characters, prefix exists
        return true;
    }
};

// ==============================================
// DRIVER CODE
// ==============================================
int main()
{
    Trie trie; // Create a Trie object

    // Insert some words
    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");

    cout << boolalpha; // Print 'true' and 'false' instead of 1 and 0

    // Word searches
    cout << "Search 'apple': " << trie.search("apple") << endl; // true
    cout << "Search 'app': " << trie.search("app") << endl;     // true
    cout << "Search 'appl': " << trie.search("appl") << endl;   // false (prefix only)
    cout << "Search 'bat': " << trie.search("bat") << endl;     // true
    cout << "Search 'bath': " << trie.search("bath") << endl;   // false

    // Prefix searches
    cout << "StartsWith 'ap': " << trie.startsWith("ap") << endl;     // true
    cout << "StartsWith 'ba': " << trie.startsWith("ba") << endl;     // true
    cout << "StartsWith 'batm': " << trie.startsWith("batm") << endl; // false

    return 0;
}
