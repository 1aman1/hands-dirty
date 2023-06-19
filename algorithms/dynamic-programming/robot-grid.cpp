#include <iostream>
#include <vector>

long number_of_ways(long row, long col)
{
    std::vector<std::vector<long>> cache(row, std::vector<long>(col, 1));

    for (int r = 1; r < row; ++r)
        for (int c = 1; c < col; ++c)
            cache[r][c] = cache[r - 1][c] + cache[r][c - 1];

    return cache[row - 1][col - 1];
}

// int number_of_ways(int row, int col)
// {
//     if (row == 1 && col == 1)
//         return 1;
//     if (row == 0 || col == 0)
//         return 0;

//     return number_of_ways(row - 1, col) + number_of_ways(row, col - 1);
// }

int main()
{
    std::cout << number_of_ways(18, 18) << "\n";
    return 0;
}