#include <iostream>
#include <vector>

class Solution
{
public:
    int climbStairs(int N, std::vector<int> &cache)
    {
        if (N < 0)
            return 0;
        else if (N == 0)
            return 1;
        else if (cache[N] > -1)
            return cache[N];
        else
        {
            cache[N] = climbStairs(N - 1, cache) + climbStairs(N - 2, cache);
            return cache[N];
        }
    }

    int climbStairs(int N)
    {
        std::vector<int> cache(N + 1, -1);

        return climbStairs(N, cache);
    }
};

int main()
{
    std::cout << climbStairs(10);

    return 0;
}