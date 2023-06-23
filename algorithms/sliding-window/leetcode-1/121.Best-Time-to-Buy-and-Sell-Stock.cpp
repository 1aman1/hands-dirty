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

int main()
{
    Solution obj;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << obj.maxProfit(prices);

    return 0;
}