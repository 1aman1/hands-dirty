#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0;

        for (auto num : nums)
        {
            if (i < 1 || nums[i - 1] < num)
            {
                nums[i++] = num;
            }
        }
        return i;
    }
};

int main()
{
    Solution obj;
    vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int count = obj.removeDuplicates(nums);
    // for (auto i = nums.begin(); i != nums.begin() + count; ++i)
    cout << count;
    return 0;
}