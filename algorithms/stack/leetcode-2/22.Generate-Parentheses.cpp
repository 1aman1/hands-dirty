#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <bitset>
#include <list>

using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        generator(n, 0 /*open*/, 0 /*close*/, "", result);
        return result;
    }

private:
    void generator(int n, int open, int close, string combinations, vector<string> &result)
    {
        if (open == n && close == n)
        {
            result.push_back(combinations);
            return;
        }
        if (open < n)
        {
            generator(n, open + 1, close, combinations + '(', result);
        }
        if (close < open)
        {
            generator(n, open, close + 1, combinations + ')', result);
        }
    }
};

int main()
{
    Solution obj;

    for (const auto &i : obj.generateParenthesis(3))
        cout << i << "\n";
    return 0;
}