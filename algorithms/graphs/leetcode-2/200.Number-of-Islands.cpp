class Solution
{
    int row_;
    int col_;

    vector<vector<bool>> visited_;

    bool Explore_Land(int row, int col, const vector<vector<char>> &grid)
    {
        bool rowCheck = 0 <= row && row < row_;
        bool colCheck = 0 <= col && col < col_;

        if (!rowCheck || !colCheck)
            return false;

        if (grid[row][col] == '0')
            return false;

        if (visited_[row][col])
            return false;

        visited_[row][col] = true;

        Explore_Land(row + 1, col, grid);
        Explore_Land(row - 1, col, grid);
        Explore_Land(row, col + 1, grid);
        Explore_Land(row, col - 1, grid);

        return true;
    }

    void Reset_Visited()
    {
        visited_.resize(row_);
        for (int i = 0; i < row_; ++i)
            visited_[i].resize(col_);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int total_islands = 0;

        row_ = grid.size();
        col_ = grid[0].size();

        Reset_Visited();

        for (int i = 0; i < row_; ++i)
        {
            for (int j = 0; j < col_; ++j)
            {
                if (Explore_Land(i, j, grid))
                    ++total_islands;
            }
        }

        return total_islands;
    }
};