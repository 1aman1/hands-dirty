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
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int resultantArea = 0;

        while (left < right)
        {
            int localArea = min(height[left], height[right]) * (right - left);
            resultantArea = max(resultantArea, localArea);

            if (height[left] < height[right])
                ++left;
            else
                --right;
        }

        return resultantArea;
    }
};

int main()
{
    Solution obj;

    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << obj.maxArea(height) << endl;

    return 0;
}