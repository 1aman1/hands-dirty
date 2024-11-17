#include <numeric>
#include <iostream>

class TrieNode
{
public:
    TrieNode *children[26];
    bool isWord;

    TrieNode()
    {
        std::fill(children, children + 26, nullptr);
        isWord = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    // insert
    void insert(std::string word)
    {

        TrieNode *itr = root;

        for (int i = 0; i < word.size(); ++i)
        {
            int index = word[i] - 'a';
            if (itr->children[index] == nullptr)
                itr->children[index] = new TrieNode();

            itr = itr->children[index];
        }

        itr->isWord = true;
    }

    // search
    bool search(std::string word)
    {
        TrieNode *itr = root;
        for (int i = 0; i < word.size(); ++i)
        {
            int index = word[i] - 'a';
            if (itr->children[index] == nullptr)
                return false;

            itr = itr->children[index];
        }
        return itr->isWord;
    }

    // startsWith
    bool startsWith(std::string word)
    {
        TrieNode *itr = root;

        for (int i = 0; i < word.size(); ++i)
        {
            int index = word[i] - 'a';
            if (itr->children[index] == nullptr)
                return false;

            itr = itr->children[index];
        }

        return true;
    }
};

int main()
{
    Trie obj;

    obj.insert("dictionary");

    std::cout << std::boolalpha << obj.search("dictionary") << std::endl;
    std::cout << std::boolalpha << obj.startsWith("d") << std::endl;

    std::cout << std::boolalpha << obj.startsWith("n") << std::endl;

    return 0;
}