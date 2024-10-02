class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        sort(citations.rbegin(), citations.rend());
        int hIndex = 0;
        while (hIndex < citations.size() && citations[hIndex] >= hIndex + 1)
        {
            ++hIndex;
        }
        return hIndex;
    }
};