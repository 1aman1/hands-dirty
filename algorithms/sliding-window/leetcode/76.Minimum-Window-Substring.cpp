#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string minWindow(string str, string pattern)
    {

        vector<int> cache(128);
        int requiredCharCount = pattern.length();
        int strSize = str.length();

        int minStart = -1;
        int minLen = strSize + 1;

        for (const auto &eachChar : pattern)
            ++cache[eachChar];

        for (int left = 0, right = 0; right < strSize; ++right)
        {
            if (--cache[str[right]] >= 0)
                --requiredCharCount;

            while (requiredCharCount == 0)
            {
                if (minLen > right - left + 1)
                {
                    minLen = right - left + 1;
                    minStart = left;
                }
                if (++cache[str[left++]] > 0)
                    ++requiredCharCount;
            }
        }

        return minStart == -1 ? "" : str.substr(minStart, minLen);
    }
};

int main()
{
    Solution obj;
    cout << obj.minWindow("ADOBECODEBANC", "ABC");

    return 0;
}