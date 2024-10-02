class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> lookup{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};

        int convertedNumber = 0;

        for (int i = 0; i < s.size() - 1; ++i)
        {
            int flag = lookup[s[i]] < lookup[s[i + 1]] ? -1 : 1;

            convertedNumber += flag * lookup[s[i]];
        }

        convertedNumber += lookup[s[s.size() - 1]];

        return convertedNumber;
    }
};