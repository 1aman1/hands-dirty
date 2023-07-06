#include <iostream>
#include <vector>
#include <ctime>

#define RANGE 99
#define SIZE 9

class Solution
{
private:
    std::vector<int> array;

public:
    int getArraySize();
    bool insert(int v);
    void initArray();

    void print();

    // implement method for ascending order
    //  Merge sort methods
    void merge_sort_partition(int, int);
    void merge(int, int, int);
};

void Solution::initArray()
{
    srand(time(nullptr));

    for (int i = 0; i < SIZE; i++)
    {
        // increase range for larger numbers
        array.push_back(rand() % RANGE);
    }
}

int Solution::getArraySize()
{
    return array.size();
}

void Solution::merge(int left, int middle, int right)
{
    // calculate the lengths, copy the corresponding elements into temp arrays

    // Once for LEFT
    int leftArraySize = middle - left + 1;
    std::vector<int> leftTEMPArray(leftArraySize);
    for (int i = 0; i < leftArraySize; ++i)
        leftTEMPArray[i] = array[left + i];

    // and RIGHT
    int rightArraySize = right - middle;
    std::vector<int> rightTEMPArray(rightArraySize);
    for (int i = 0; i < rightArraySize; ++i)
        rightTEMPArray[i] = array[middle + i + 1];

    // compare both left and right sub arrays, searching for smaller element,
    // and put the smaller element using sorted_array_offset back to array
    int left_array_offset = 0;
    int right_array_offset = 0;
    int sorted_array_offset = left;

    while (left_array_offset < leftArraySize && right_array_offset < rightArraySize)
    {
        if (leftTEMPArray[left_array_offset] <= rightTEMPArray[right_array_offset])
            array[sorted_array_offset] = leftTEMPArray[left_array_offset++];
        else
            array[sorted_array_offset] = rightTEMPArray[right_array_offset++];

        ++sorted_array_offset;
    }

    // so far we sorted elements till smallerArray.length()
    // remaining we need to manually insert.

    while (left_array_offset < leftArraySize)
        array[sorted_array_offset++] = leftTEMPArray[left_array_offset++];

    while (right_array_offset < rightArraySize)
        array[sorted_array_offset++] = rightTEMPArray[right_array_offset++];
}

void Solution::merge_sort_partition(int left, int right)
{
    // break recursion
    if (right <= left)
        return;

    int middle = left + (right - left) / 2;

    merge_sort_partition(left, middle);
    merge_sort_partition(middle + 1, right);

    // merging from here
    merge(left, middle, right);
}

void Solution::print()
{
    for (auto i : array)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main()
{
    Solution obj;
    obj.initArray();

    obj.print();
    obj.merge_sort_partition(0, obj.getArraySize() - 1);
    obj.print();
}