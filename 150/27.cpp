#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        auto endItr = std::remove_if(nums.begin(), nums.end(), [val](int num)
                                     { return num == val; });
        return std::distance(nums.begin(), endItr);
    }
};

int main()
{
    Solution obj;
    vector<int> nums{0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    int count = obj.removeElement(nums, val);
    for (auto i = nums.begin(); i != nums.begin() + count; ++i)
        cout << *i;
    return 0;
}