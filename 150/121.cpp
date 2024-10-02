class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int left = 0;
        int right = 0;
        int resultantProfit = 0;

        while (right < prices.size())
        {
            if (prices[left] < prices[right])
                resultantProfit = max(resultantProfit, prices[right] - prices[left]);
            else
                left = right;

            ++right;
        }

        return resultantProfit;
    }
};
