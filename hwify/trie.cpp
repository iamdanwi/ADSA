#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        char ch = toupper(word[0]);
        int index = ch - 'A';
        TrieNode *child;

        if (root->children[index] != nullptr)
        { // charecter is present
            child = root->children[index];
        }
        else
        { // charecter is absent
            child = new TrieNode(ch);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }
    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    void printUtil(TrieNode *node, string prefix, bool isLast)
    {
        if (node == root)
        {
            cout << "ROOT" << endl;
        }
        else
        {
            cout << prefix << (isLast ? "`-- " : "|-- ") << node->data;
            if (node->isTerminal)
            {
                cout << " *";
            }
            cout << endl;
        }

        vector<TrieNode *> existingChildren;
        for (int i = 0; i < 26; i++)
        {
            if (node->children[i] != nullptr)
            {
                existingChildren.push_back(node->children[i]);
            }
        }

        for (int i = 0; i < existingChildren.size(); i++)
        {
            string nextPrefix = prefix;
            if (node != root)
            {
                nextPrefix += (isLast ? "    " : "|   ");
            }

            printUtil(existingChildren[i], nextPrefix, i == existingChildren.size() - 1);
        }
    }

    void printTrie()
    {
        printUtil(root, "", true);
    }
};

int main()
{
    Trie t;

    t.insertWord("ram");
    t.insertWord("rat");
    t.insertWord("rope");
    t.insertWord("dog");

    t.printTrie();

    return 0;
}
