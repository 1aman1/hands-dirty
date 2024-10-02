class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        const int SIZE = ratings.size();
        vector<int> candies(SIZE, 1);  
        
        if (SIZE < 2)
        {
            return SIZE;  
        }

        for (int i = 1; i < SIZE; ++i)
        {
            if (ratings[i] > ratings[i - 1])
            {
                candies[i] = candies[i - 1] + 1;
            }
        }
        for (int i = SIZE - 2; i >= 0; --i)
        {
            if (ratings[i] > ratings[i + 1])
            {
                candies[i] = max(candies[i], candies[i + 1] + 1);  
            }
        }

        int candiesToGive = accumulate(candies.begin(), candies.end(), 0);

        return candiesToGive;
    }
};