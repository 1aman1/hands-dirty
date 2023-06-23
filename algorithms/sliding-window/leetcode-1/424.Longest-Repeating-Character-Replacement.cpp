
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        vector<int> lookup(26);
        int maxFreqCharInWindow = 0;

        int left = 0;
        int right = 0;

        int result = 0;

        while (right < s.size())
        {
            ++lookup[s[right] - 'A'];
            maxFreqCharInWindow = max(maxFreqCharInWindow, lookup[s[right] - 'A']);

            if (right - left - maxFreqCharInWindow + 1 > k)
            {
                --lookup[s[left] - 'A'];
                ++left;
            }
            result = max(result, right - left + 1);
            ++right;
        }

        return result;
    }
};

int main()
{
    string s = "AABABBA";
    int k = 1;

    Solution obj;
    cout << obj.characterReplacement(s, k);

    return 0;
}