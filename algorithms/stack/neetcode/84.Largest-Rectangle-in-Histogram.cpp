#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <bitset>
#include <stack>
#include <list>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<pair<int, int>> myStack;
        int SIZE = heights.size();
        int resultantArea = 0;

        for (int i = 0; i < SIZE; ++i)
        {
            int start = i;

            while (!myStack.empty() && myStack.top().second > heights[i])
            {
                int index = myStack.top().first;
                int width = i - index;
                int height = myStack.top().second;
                myStack.pop();

                resultantArea = max(resultantArea, height * width);
                start = index;
            }

            myStack.push({start, heights[i]});
        }

        while (!myStack.empty())
        {
            int width = SIZE - myStack.top().first;
            int height = myStack.top().second;
            myStack.pop();

            resultantArea = max(resultantArea, height * width);
        }

        return resultantArea;
    }
};

int main()
{
    Solution obj;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << obj.largestRectangleArea(heights);

    return 0;
}