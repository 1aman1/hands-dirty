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
    void insertionSort();
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

void Solution::print()
{
    for (auto i : array)
        std::cout << i << " ";
    std::cout << std::endl;
}

void Solution::insertionSort()
{
    for (int i = 1; i < array.size(); ++i)
    { // compare the current element with previous sequence, and find appropriate index for it

        int curr_element = array.at(i);
        int traverseBack = i - 1;
        while (curr_element < array.at(traverseBack))
        {
            array[traverseBack + 1] = array[traverseBack];
            --traverseBack;
        }
        array[traverseBack + 1] = curr_element;
    }
}

int main()
{
    Solution obj;
    obj.initArray();

    obj.print();
    obj.insertionSort();
    obj.print();
}