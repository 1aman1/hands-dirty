
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <bitset>
#include <list>

using namespace std;

/*
    Given elevation map array, compute trapped water
    Ex. height = [0,1,0,2,1,0,1,3,2,1,2,1] -> 6

    2 pointers, outside in, track max left/right
    For lower max, curr only dependent on that one
    Compute height of these, iterate lower one

    Time: O(n)
    Space: O(1)
*/

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int l = 0;
        int r = height.size() - 1;

        int maxLeft = height[l];
        int maxRight = height[r];

        int result = 0;

        while (l < r)
        {
            if (maxLeft <= maxRight)
            {
                ++l;
                maxLeft = max(maxLeft, height[l]);
                result += maxLeft - height[l];
            }
            else
            {
                --r;
                maxRight = max(maxRight, height[r]);
                result += maxRight - height[r];
            }
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
