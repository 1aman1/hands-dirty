class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int result = 0;

        while (n != 0)
        {
            // std::cout << n << " " << std::bitset<8>(n) << endl;
            if (n & 1)
                result++;
            n = n >> 1;
        }

        return result;
    }
};