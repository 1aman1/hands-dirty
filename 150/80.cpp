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

        int writerPos = 0;
        int readerPos = 1;
        bool isSeenAlready = false;

        while (readerPos < size)
        {
            if (readerPos < size && nums[writerPos] != nums[readerPos])
            {
                nums[++writerPos] = nums[readerPos++];
                isSeenAlready = false;
            }
            if (readerPos < size && nums[writerPos] == nums[readerPos])
            {
                if (isSeenAlready)
                {
                    ++readerPos;
                    continue;
                }
                else
                {
                    ++writerPos;
                    nums[writerPos] = nums[readerPos];
                    ++readerPos;
                    isSeenAlready = true;
                }
            }
        }
        return writerPos + 1;
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