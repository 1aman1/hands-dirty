#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int size = nums.size();
        if (size <= 2)
        {
            return size;
        }

        int writerPos = 1;
        int count = 1;

        for (int readerPos = 1; readerPos < size; ++readerPos)
        {
            if (nums[readerPos] == nums[readerPos - 1])
            {
                ++count;
            }
            else
            {
                count = 1;
            }
            if (count <= 2)
            {
                nums[writerPos++] = nums[readerPos];
            }
        }

        return writerPos ;
    }
};

int main()
{
    Solution obj;
    vector<int> nums{1, 1, 1, 2};
    // vector<int> nums{0, 0, 1, 1, 1, 1, 2, 3, 3};
    cout << obj.removeDuplicates(nums);
    return 0;
}