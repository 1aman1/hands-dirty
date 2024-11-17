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
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int lowRow = 0;
        int highRow = matrix.size() - 1;

        while (lowRow < highRow)
        {
            int mid = lowRow + (highRow - lowRow) / 2;
            if (matrix[mid][0] == target)
            {
                return true;
            }
            if (matrix[mid][0] < target && target < matrix[mid + 1][0])
            {
                lowRow = mid;
                break;
            }

            if (matrix[mid][0] < target)
            {
                lowRow = mid + 1;
            }
            else // matrix[mid][0] >target)
            {
                highRow = mid - 1;
            }
        }

        int leftCol = 0;
        int rightCol = matrix[0].size() - 1;

        while (leftCol <= rightCol)
        {
            int mid = leftCol + (rightCol - leftCol) / 2;
            if (matrix[lowRow][mid] == target)
            {
                return true;
            }
            if (matrix[lowRow][mid] < target)
            {
                leftCol = mid + 1;
            }
            else
            {
                rightCol = mid - 1;
            }
        }

        return false;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1}, {3}};
    // vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};

    Solution obj;

    int target = 4;
    std::cout << std::boolalpha
              << obj.searchMatrix(matrix, target)
              << endl;

    return 0;
}