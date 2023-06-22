#include <iostream>
#include <vector>

int elementAt(size_t pos, const std::vector<int> &array)
{
    int i = pos - 1;
    if (0 <= i && i < array.size())
        return array[i];

    return -1;
}

bool binary_search_special(int left, int right, const std::vector<int> &array, const int &target)
{
    int mid;
    while (left <= right)
    {
        mid = (right - left) / 2 + left;
        int middle = elementAt(mid, array);

        if (target < middle || middle == -1)
            right = mid - 1;
        else if (middle < target)
            left = mid + 1;
        else // if (middle == target)
            return true;
    }
    return false;
}

bool search(const std::vector<int> &array, const int &target)
{
    int pos = 1;
    while (elementAt(pos, array) != -1 && elementAt(pos, array) < target)
        pos *= 2;
    return binary_search_special(pos / 2, pos, array, target);
}

int main()
{
    std::vector<int> array = {1, 2, 3, 4, 5, 6, 7};

    int target = 5;
    std::cout << search(array, target);

    return 0;
}