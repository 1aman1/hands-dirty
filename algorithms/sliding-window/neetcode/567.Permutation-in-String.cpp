
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        const int S1_SIZE = s1.length();
        const int S2_SIZE = s2.length();

        if (S1_SIZE > S2_SIZE)
        {
            return false;
        }

        vector<int> cache(128);
        int patternSize = s1.length();

        for (const auto &eachChar : s1)
            ++cache[eachChar];

        for (int i = 0; i < s2.length(); ++i)
        {
            if (--cache[s2[i]] >= 0)
                --patternSize;

            if (i >= S1_SIZE)
            {
                if (++cache[s2[i - S1_SIZE]] > 0)
                    ++patternSize;
            }

            if (patternSize == 0)
                return true;
        }

        return false;
    }
};

int main()
{
    Solution obj;

    string s1 = "ab", s2 = "eidbaooo";

    cout << boolalpha
         << obj.checkInclusion(s1, s2)
         << "\n";

    return 0;
}
