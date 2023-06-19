#include <iostream>
#include <vector>
#include <ctime>

class debugUtil
{
    bool DEBUGLOG = false;

public:
    debugUtil(){};

    void setDebugTrue()
    {
        DEBUGLOG = true;
    }

    bool ifDEBUGLOG()
    {
        return DEBUGLOG;
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
    ifDEBUGLOG() == true ? std::cout << "BUILDING MaxHeap ON :" << std::endl : std::cout << "";

    for (auto i : array)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    Solution obj;
    obj.initArray();

    if (argc == 2)
    {
        if ("true" == static_cast<std::string>(*(argv + 1)))
            obj.setDebugTrue();
    }

    obj.print();

    obj.print();
}
