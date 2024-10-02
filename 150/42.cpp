class Solution
{
public:
    int trap(vector<int> &height)
    {
        int SIZE = height.size();
        
        if (SIZE < 3)
        {
            return 0;
        }

        vector<int> leftMaxHeight(SIZE), rightMaxHeight(SIZE);

        leftMaxHeight[0] = height[0];
        for (int i = 1; i < SIZE; ++i)
        {
            leftMaxHeight[i] = max(leftMaxHeight[i - 1], height[i]);
        }

        rightMaxHeight[SIZE - 1] = height[SIZE - 1];
        for (int i = SIZE - 2; i >= 0; --i)
        {
            rightMaxHeight[i] = max(rightMaxHeight[i + 1], height[i]);
        }

        int totalWater = 0;

        for (int i = 0; i < SIZE; ++i)
        {
            totalWater += min(rightMaxHeight[i], leftMaxHeight[i]) - height[i];
        }

        return totalWater;
    }
};