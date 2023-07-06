class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        // push stones into maxHeap
        for (int i = 0; i < stones.size(); ++i)
            maxHeap.push(stones[i]);

        while (maxHeap.size() > 1)
        {
            int heavierStone = maxHeap.top();
            maxHeap.pop();
            int lighterStone = maxHeap.top();
            maxHeap.pop();

            // otherwise, take difference and push , and continue
            if (heavierStone > lighterStone)
                maxHeap.push(heavierStone - lighterStone);
        }

        if (maxHeap.size() == 0)
            return 0;

        return maxHeap.top();
    }

private:
    priority_queue<int> maxHeap;
};