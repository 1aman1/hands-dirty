#include <iostream>
#include <vector>
#include <ctime>

class debugUtil
{
    bool log;

public:
    debugUtil(){};
    
    void setDebugTrue()
    {
        log = true;
    }
    bool ifDEBUGLOG()
    {
        return log;
    }
};

class Solution : public debugUtil
{
private:
    int RangeForRandom = 99;
    int SequenceSize = 10;

public:
    void initArray();
    void print();

    void selectionSort();

private:
    std::vector<int> array;
};

void Solution::initArray()
{
    srand(time(nullptr));

    for (int i = 0; i < SequenceSize; i++)
    {
        array.push_back(rand() % RangeForRandom);
    }
}

void Solution::print()
{
    for (auto i : array)
        std::cout << i << " ";
    std::cout << std::endl;
}

/*
selectionSort
*/

void Solution::selectionSort()
{
    for (int i = 0; i < array.size(); ++i)
    {
        int minValueIndex = i;
        for (int j = i + 1; j < array.size(); ++j)
        { // traverse the array ahead of i, to find relatively smaller element
            if (array[j] < array[minValueIndex])
                minValueIndex = j;
        }
        if (minValueIndex != i) // it was set before this loop
        {
            array[i] = array[i] ^ array[minValueIndex];
            array[minValueIndex] = array[i] ^ array[minValueIndex];
            array[i] = array[i] ^ array[minValueIndex];
        }
    }
}


int main(int argc, char **argv)
{
    Solution obj;

    if (argc == 2)
    {
        std::string opt = static_cast<std::string>(*(argv + 1));
        if (opt == "true")
            obj.setDebugTrue();
    }

    obj.initArray();
    obj.print();

    obj.selectionSort();
    obj.print();

}