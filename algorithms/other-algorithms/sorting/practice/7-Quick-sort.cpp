#include <iostream>
#include <vector>
#include <ctime>

class _debugUtil
{
    bool _log;

public:
    _debugUtil()
    {
        _log = false;
    };

    void setDebugTrue()
    {
        _log = true;
    }

    bool _ifDEBUGLOG()
    {
        return _log;
    }
};

class Solution : public _debugUtil
{
private:
    int RangeForRandom = 99;
    int SequenceSize = 10;

public:
    void initArray();
    void print();

    // quick sort methods
    int partition(int, int);
    void quicksort(int, int);

private:
    std::vector<int> array;
};

void Solution::initArray()
{
    srand(time(nullptr));

    for (int i = 0; i < SequenceSize; i++)
        array.push_back(rand() % RangeForRandom);
}

void Solution::print()
{
    std::cout << std::endl;
    for (auto i : array)
        std::cout << i << " ";
    std::cout << std::endl;
}

void Solution::quicksort(int left, int right)
{
    if (left < right)
    {
        //  divides the array, based on pivot
        int q = partition(left, right);

        _ifDEBUGLOG() == true ? std::cout << "left:" << left << " q:" << q << " right:" << right << std::endl : std::cout << "";

        quicksort(left, q - 1);
        quicksort(q + 1, right);
    }
}

int Solution::partition(int left, int right)
{
    // right most element is pivot
    int pivotValue = array[right];

    _ifDEBUGLOG() == true ? std::cout << "pivot " << pivotValue << std::endl : std::cout << "";
    if (_ifDEBUGLOG() == true)
        print();

    int i = left - 1;

    for (int j = left; j < right; ++j)
    {
        if (array[j] <= pivotValue)
        {
            i += 1;

            // swap

            if (i != j)
            {
                std::swap(array[i], array[j]);
                _ifDEBUGLOG() == true ? std::cout << "swapping " << array[i] << " " << array[j] << std::endl : std::cout << "";
            }
        }
        _ifDEBUGLOG() == true ? std::cout << "pivot " << pivotValue << " j: " << j << std::endl : std::cout << "";
    }

    _ifDEBUGLOG() == true ? std::cout << "swapping " << array[i + 1] << " " << array[right] << std::endl : std::cout << "";

    std::swap(array[i + 1], array[right]);
    return (i + 1);
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
    obj.quicksort(0, 9);
    obj.print();
}
