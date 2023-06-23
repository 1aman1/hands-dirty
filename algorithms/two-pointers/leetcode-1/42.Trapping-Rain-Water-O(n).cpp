
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
    int trap(vector<int> &height)
    {
        int SIZE = height.size();

        vector<int> maxLeft(SIZE);
        vector<int> maxRight(SIZE);
        vector<int> minLeftRight(SIZE);
        int maxValue = 0;
        int result = 0;

        for (int i = 1; i < SIZE; ++i)
        {
            if (maxValue < height[i - 1])
                maxValue = height[i - 1];
            maxLeft[i] = maxValue;
        }

        maxValue = 0;
        for (int i = SIZE - 1 - 1; i >= 0; --i)
        {
            if (maxValue < height[i + 1])
                maxValue = height[i + 1];
            maxRight[i] = maxValue;
        }

        for (int i = 0; i < SIZE; ++i)
        {
            minLeftRight[i] = min(maxLeft[i], maxRight[i]);
        }

        for (int i = 0; i < SIZE; ++i)
        {
            if (minLeftRight[i] - height[i] > 0)
                result += minLeftRight[i] - height[i];
        }

        return result;
    }
};

int main()
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution obj;
    cout << obj.trap(height);

    return 0;
}
