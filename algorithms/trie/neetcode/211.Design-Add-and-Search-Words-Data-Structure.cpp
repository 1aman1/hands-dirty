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

class WordDictionary
{
    TrieNode *root;

public:
    WordDictionary()
    {
        root = new TrieNode();
    }

    void addWord(string word)
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

    bool search(string word)
    {
        TrieNode *node = root;
        return searchInNode(word, 0, node);
    }

    bool searchInNode(string &word, int i, TrieNode *node)
    {
        if (node == nullptr)
            return false;

        if (i == word.size())
            return node->isWord;

        if (word[i] != '.')
            return searchInNode(word, i + 1, node->children[word[i] - 'a']);

        for (int j = 0; j < 26; ++j)
        {
            if (searchInNode(word, i + 1, node->children[j]))
                return true;
        }

        return false;
    }
};