#include <iostream>
#include <vector>

void sorted_merge(std::vector<int> &array_A, std::vector<int> &array_B)
{
    int offset_B = array_B.size() - 1;
    int offset_A = array_A.size() - offset_B - 2;
    int offset_sorted_A = array_A.size() - 1;

    while (offset_B >= 0)
    {
        if (array_A[offset_A] > array_B[offset_B])
        {
            array_A[offset_sorted_A] = array_A[offset_A];
            --offset_sorted_A;
            --offset_A;
        }
        else
        {
            array_A[offset_sorted_A] = array_B[offset_B];
            --offset_sorted_A;
            --offset_B;
        }
    }
}

int main()
{
    std::vector<int> array_A = {1, 2, 15, 30, 40, 60, 80, 90, 100, -1, -1, -1, -1, -1};
    std::vector<int> array_B = {5, 7, 16, 20, 50};

    for (const auto &i : array_A)
        std::cout << i << " ";
    std::cout << "\n";

    for (const auto &i : array_B)
        std::cout << i << " ";
    std::cout << "\n";

    sorted_merge(array_A, array_B);

    std::cout << "\nMerged";
    for (const auto &i : array_A)
        std::cout << i << " ";
    std::cout << "\n";

    return 0;
}