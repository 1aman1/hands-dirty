#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

class Solution
{
public:
    class Coord
    {
    public:
        int x;
        int y;
        long double distance;

        Coord(int x, int y)
        {
            this->x = x;
            this->y = y;
            this->distance = pow(x, 2) + pow(y, 2);
        }
    };

    class CustomComparator
    {
    public:
        bool operator()(const Coord &lhs, const Coord &rhs)
        {
            return lhs.distance < rhs.distance;
        }
    };

    vector<vector<int>>
    kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<Coord, vector<Coord>, CustomComparator> maxHeap;

        for (int i = 0; i < points.size(); ++i)
        {
            maxHeap.push(Coord(points[i][0], points[i][1]));
        }

        while (maxHeap.size() > k)
            maxHeap.pop();

        vector<vector<int>> result;

        for (int i = 0; i < k; ++i)
        {
            result.push_back({maxHeap.top().x, maxHeap.top().y});
            maxHeap.pop();
        }

        return result;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> points = {{{9997, 9997}, {9996, 9998}}};

    vector<vector<int>> result = obj.kClosest(points, 1);

    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i][0] << result[i][1] << endl;
    }

    return 0;
}