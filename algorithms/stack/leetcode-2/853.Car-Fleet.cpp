#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <bitset>
#include <list>

using namespace std;

class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        int SIZE = position.size();

        vector<pair<int, double>> carInfo;

        for (int i = 0; i < SIZE; ++i)
        {
            double time = (double)(target - position[i]) / speed[i];
            carInfo.push_back({position[i], time});
        }

        sort(begin(carInfo), end(carInfo));

        int result = 0;
        double maxTime = 0;

        for (int i = SIZE - 1; i >= 0; --i)
        {
            double time = carInfo[i].second;
            if (time > maxTime)
            {
                maxTime = time;
                ++result;
            }
        }

        return result;
    }
};

int main()
{
    Solution obj;

    int target = 12;
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};

    cout << obj.carFleet(target, position, speed);

    return 0;
}