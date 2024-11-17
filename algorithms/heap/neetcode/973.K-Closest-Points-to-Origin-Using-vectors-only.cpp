#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
// O(k logn) solution
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<vector<int>> triples;
        for (auto &eachPoint : points)
        {
            triples.push_back({eachPoint[0] * eachPoint[0] + eachPoint[1] * eachPoint[1],
                               eachPoint[0],
                               eachPoint[1]});
        }

        // Min heap of vectors (triples). This constructor takes O(n) time (n = len(v))

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq(triples.begin(), triples.end());
        vector<vector<int>> res;

        while (k > 0)
        {
            vector<int> tmp = pq.top();
            pq.pop();
            res.push_back({tmp[1], tmp[2]});
            --k;
        }
        return res;
    }
};

int main()
{
    Solution obj;

    // vector<vector<int>> points = {{{9997, 9997}, {9996, 9998}}};
    vector<vector<int>> points = {{{30, 5}, {25, 5}, {20, 6}, {33, 6}, {23, 5}}};

    vector<vector<int>> result = obj.kClosest(points, 1);

    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i][0] << result[i][1] << endl;
    }

    return 0;
}