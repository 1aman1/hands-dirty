#include <iostream>
#include <vector>
#include <ctime>

class debugUtil
{
    bool DEBUGLOG;

public:
    debugUtil()
    {
        DEBUGLOG = false;
    };

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

    void shellSort();

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

void Solution::shellSort()
{
    for (int GAP = array.size() / 2; GAP > 0; GAP /= 2)
    {
        for (int i = GAP; i < array.size(); ++i)
        {
            int i_copy = array[i];
            int j;
            for (j = i; j >= GAP && i_copy < array[j - GAP]; j -= GAP)
            {
                array[j] = array[j - GAP];
            }
            array[j] = i_copy;
        }
    }
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
    obj.shellSort();
    obj.print();
}
