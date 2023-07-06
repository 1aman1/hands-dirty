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

    // implement method for ascending order
    void bubble_sort();

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
Bubble Sort
*/

void Solution::bubble_sort()
{ // use flag for previous swap, if any

    bool ifSwappedThenContinue;
    for (int i = 0; i < array.size() - 1; ++i)
    {
        ifSwappedThenContinue = false;
        for (int j = 0; j < array.size() - 1 - i; ++j)
        {
            if (!(array[j] < array[j + 1]))
            { // swap
                array[j] = array[j] ^ array[j + 1];
                array[j + 1] = array[j] ^ array[j + 1];
                array[j] = array[j] ^ array[j + 1];
                ifSwappedThenContinue = true;
            }

            if (ifSwappedThenContinue == false)
                break;
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

    obj.print();
}