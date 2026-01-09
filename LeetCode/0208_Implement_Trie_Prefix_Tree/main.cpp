#include <string>

using namespace std;

class TrieNode
{
public:
    TrieNode *children[26];
    bool isEndOfWord;

    TrieNode()
    {
        isEndOfWord = false;
        for (int i = 0; i < 26; ++i)
        {
            children[i] = nullptr;
        }
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *current = root;

        for (char character : word)
        {
            int index = character - 'a';

            if (current->children[index] == nullptr)
            {
                current->children[index] = new TrieNode();
            }

            current = current->children[index];
        }

        current->isEndOfWord = true;
    }

    bool search(string word)
    {
        TrieNode *current = root;

        for (char character : word)
        {
            int index = character - 'a';

            if (current->children[index] == nullptr)
            {
                return false;
            }

            current = current->children[index];
        }

        return current->isEndOfWord;
    }

    bool startsWith(string prefix)
    {
        TrieNode *current = root;

        for (char character : prefix)
        {
            int index = character - 'a';

            if (current->children[index] == nullptr)
            {
                return false;
            }

            current = current->children[index];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */