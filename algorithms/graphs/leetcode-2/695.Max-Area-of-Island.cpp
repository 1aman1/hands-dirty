class Solution
{
    int row_;
    int col_;

    vector<vector<bool>> visited_;

    int Explore_Land(int row, int col, const vector<vector<int>> &grid)
    {
        bool rowCheck = 0 <= row && row < row_;
        bool colCheck = 0 <= col && col < col_;

        if (!rowCheck || !colCheck)
            return false;

        if (grid[row][col] == false)
            return false;

        if (visited_[row][col])
            return false;

        visited_[row][col] = true;
        int size = 1;

        size += Explore_Land(row + 1, col, grid);
        size += Explore_Land(row - 1, col, grid);
        size += Explore_Land(row, col + 1, grid);
        size += Explore_Land(row, col - 1, grid);

        return size;
    }

    void Reset_Visited()
    {
        visited_.resize(row_);
        for (int i = 0; i < row_; ++i)
            visited_[i].resize(col_);
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int maxArea = 0;

        row_ = grid.size();
        col_ = grid[0].size();

        Reset_Visited();

        for (int i = 0; i < row_; ++i)
        {
            for (int j = 0; j < col_; ++j)
            {
                int area = Explore_Land(i, j, grid);
                maxArea = std::max(maxArea, area);
            }
        }

        return maxArea;
    }
};