#include <bits/stdc++.h>
using namespace std;

#include "trie/Trie.h"
#include "utils/FileUtils.h"

int main()
{
    Trie trie; // create an instance of Trie

    // load words from file
    vector<string> words = FileUtils::readWordsFromFile("data/dictionary.txt");

    // insert each word into our trie
    for (const string &word : words)
    {
        trie.insert(word);
    }

    // loop for user interaction
    bool flag = true;

    string prefix;
    while (flag == true)
    {
        cout << "\nStart Entering a word or type 'exit' to quit : ";
        cin >> prefix;

        if (prefix == "exit")
        {
            cout << "Exiting auto-complete system by Dhiraj...";
            flag = false;
        }

        // get suggestions based on prefix
        vector<string> suggestions = trie.getSuggestions(prefix);

        // Print suggestions
        if (suggestions.empty())
        {
            cout << "No suggestions found for prefix: " << prefix << endl;
        }
        else
        {
            cout << "Suggestions for prefix: " << endl;

            for (const string &suggestion : suggestions)
            {
                cout << " - " << suggestion << endl;
            }
        }
    }

    return 0;
}