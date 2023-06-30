
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        std::unordered_set<int> cache(begin(nums), end(nums));
        int longestSequenceLength = -1;

        for (const auto &eachNum : nums)
        {
            if (!cache.count(eachNum - 1)) // if prev doesn't exist
            {
                int length = 1;
                while (cache.count(eachNum + length))
                    ++length;

                longestSequenceLength = std::max(length, longestSequenceLength);
            }
        }
        return longestSequenceLength;
    }
};
