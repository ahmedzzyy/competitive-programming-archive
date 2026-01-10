#include <string>

using namespace std;

class TrieNode
{
public:
    TrieNode *children[26];
    bool isEndOfWord;

    TrieNode() : children{}, isEndOfWord(false) {}
};

class WordDictionary
{
private:
    TrieNode *root;

    bool searchInNode(const string &word, int index, TrieNode *node)
    {
        if (index == word.size())
            return node->isEndOfWord;

        char character = word[index];

        if (character == '.')
        {
            for (TrieNode *child : node->children)
            {
                if (child && searchInNode(word, index + 1, child))
                    return true;
            }

            return false;
        }

        int childIndex = character - 'a';
        TrieNode *child = node->children[childIndex];

        if (!child)
            return false;

        return searchInNode(word, index + 1, child);
    }

public:
    WordDictionary() : root(new TrieNode()) {}

    void addWord(string word)
    {
        TrieNode *current = root;

        for (char character : word)
        {
            int index = character - 'a';

            if (!current->children[index])
            {
                current->children[index] = new TrieNode();
            }

            current = current->children[index];
        }

        current->isEndOfWord = true;
    }

    bool search(string word)
    {
        return searchInNode(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */