#include <iostream>
#include <vector>

class Solution
{
    std::vector<std::vector<int>> result_;

    void dfs(std::vector<int> &nums, int left, int right)
    {
        if (left == right)
        {
            result_.push_back(nums);
            return;
        }

        for (auto i = left; i <= right; ++i)
        {
            std::swap(nums[i], nums[left]);
            dfs(nums, left + 1, right);
            std::swap(nums[i], nums[left]);
        }
    }

public:
    std::vector<std::vector<int>> permute(std::vector<int> &nums)
    {
        dfs(nums, 0, nums.size() - 1);

        return result_;
    }
};

void print(const std::vector<std::vector<int>> &result)
{
    for (auto row : result)
    {
        for (auto col : row)
        {
            std::cout << col << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::vector<int> nums = {1, 2, 3};
    Solution obj;

    std::vector<std::vector<int>> result = obj.permute(nums);

    print(result);

    return 0;
}