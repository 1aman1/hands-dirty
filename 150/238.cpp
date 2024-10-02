class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int numsSize = nums.size();
        vector<int> prefix(numsSize, 1);
        vector<int> suffix(numsSize, 1);
        vector<int> result(numsSize, 1);

        prefix[0] = 1;
        for (int i = 1; i < numsSize; ++i)
        {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }
        suffix[0] = 1;
        for (int i = numsSize - 2; i >= 0; --i)
        {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < numsSize; ++i)
        {
            result[i] = prefix[i] * suffix[i];
        }

        return result;
    }
};