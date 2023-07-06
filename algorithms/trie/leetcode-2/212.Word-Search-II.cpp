
class TrieNode
{
public:
    TrieNode *children[26];
    bool isWord;
    TrieNode()
    {
        fill(children, children + 26, nullptr);
        isWord = false;
    }
};

class Solution
{
    TrieNode *root = new TrieNode();

public:
    void insert(string word)
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

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        for (int i = 0; i < words.size(); ++i)
        {
            insert(words[i]);
        }

        int ROW = board.size();
        int COLUMN = board[0].size();

        TrieNode *node = root;
        vector<string> result;

        for (int i = 0; i < ROW; ++i)
        {
            for (int j = 0; j < COLUMN; ++j)
            {
                search(board, i, j, ROW, COLUMN, result, "", node);
            }
        }

        return result;
    }

    void search(vector<vector<char>> &board, int i, int j, int ROW, int COLUMN, vector<string> &result, string word, TrieNode *node)
    {
        bool rowCheck = 0 <= i && i < ROW;
        bool colCheck = 0 <= j && j < COLUMN;

        if (!rowCheck || !colCheck)
            return;

        if (board[i][j] == '$')
            return;

        char currChar = board[i][j];

        node = node->children[board[i][j] - 'a'];
        if (node == nullptr)
            return;

        word += board[i][j];

        if (node->isWord == true)
        {
            result.push_back(word);
            node->isWord = false;
        }

        board[i][j] = '$';

        search(board, i, j + 1, ROW, COLUMN, result, word, node);
        search(board, i, j - 1, ROW, COLUMN, result, word, node);
        search(board, i - 1, j, ROW, COLUMN, result, word, node);
        search(board, i + 1, j, ROW, COLUMN, result, word, node);

        board[i][j] = currChar;
    }
};