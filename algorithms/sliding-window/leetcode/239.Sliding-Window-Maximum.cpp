#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        vector<int> result;

        int i = 0;
        int j = 0;

        while (j < nums.size())
        {
            while (!dq.empty() && nums[dq.back()] < nums[j])
            {
                dq.pop_back();
            }
            dq.push_back(j);

            if (i > dq.front())
            {
                dq.pop_front();
            }

            if (j + 1 >= k)
            {
                result.push_back(nums[dq.front()]);
                i++;
            }
            j++;
        }

        return result;
    }
};

int main()
{
    std::vector<int> v{1, 3, -1, -3, 5, 3, 6, 7};

    Solution obj;
    for (const auto &i : obj.maxSlidingWindow(v, 3))
        cout << i << "\t";

    return 0;
}