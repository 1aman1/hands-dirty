#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <bitset>
#include <list>
#include <cmath>

using namespace std;

class Solution
{
public:
    int minEatingSpeed(vector<int> &pile, int h)
    {
        int SIZE = pile.size();

        int low = 1;
        int high = *(max_element(begin(pile), end(pile)));
        int result = high;

        while (low <= high)
        {
            int k = low + (high - low) / 2;
            long int hours = 0;
            for (int i = 0; i < SIZE; ++i)
            {
                hours += ceil((double)pile[i] / k);
            }
            if (hours <= h)
            {
                result = min(k, result);
                high = k - 1;
            }
            else
            {
                low = k + 1;
            }
        }

        return result;
    }
};

int main()
{
    Solution obj;

    vector<int> pile = {3, 6, 7, 11};
    int h = 8;

    cout << obj.minEatingSpeed(pile, h);
    return 0;
}