#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> curr;
        vector<vector<int>> result;
        dfs(nums, 0, curr, result);
        
        return result;
    }

private:
    void dfs(vector<int> &nums, int start, vector<int> &curr, vector<vector<int>> &result)
    {
        result.push_back(curr);

        for (int i = start; i < nums.size(); i++)
        {
            curr.push_back(nums[i]);
            dfs(nums, i + 1, curr, result);
            curr.pop_back();
        }
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {1, 2, 2};

    vector<vector<int>> subsets = obj.subsets(nums);

    for (int i = 0; i < subsets.size(); ++i)
    {
        for (int j = 0; j < subsets[i].size(); ++j)
        {
            cout << subsets[i][j];
        }
        cout << endl;
    }

    return 0;
}