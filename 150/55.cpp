class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int SIZE = nums.size();
        int reachable = 0;

        for (int i = 0; i < SIZE; i++)
        {
            if (reachable < i)
            {
                return false;
            }
            
            reachable = max(reachable, i + nums[i]);
            if (reachable >= SIZE -1)
            {
                break;
            }
        }

        return true;
    }
};
