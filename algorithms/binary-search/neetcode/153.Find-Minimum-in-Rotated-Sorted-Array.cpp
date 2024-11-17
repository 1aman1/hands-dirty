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
    int findMin(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        int result = nums[0];

        while (left <= right)
        {
            if (nums[left] < nums[right])
            {
                result = min(result, nums[left]);
                break;
            }

            int mid = (right - left) / 2 + left;
            result = min(result, nums[mid]);

            if (nums[left] <= nums[mid])
                left = mid + 1;
            else
                right = mid - 1;
        }

        return result;
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {3, 4, 5, 1, 2};
    cout << obj.findMin(nums);
    return 0;
}