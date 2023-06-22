#include <iostream>
#include <vector>
#include <ctime>

class debugUtil
{
    bool log;

public:
    debugUtil() { log = false; };

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

    // heap members
    int PARENT(int i);
    int LEFT(int i);
    int RIGHT(int i);

    void BuildMaxHeap();
    void Heapify(int, int);

    //  Heap sort
    void heapSort();

private:
    std::vector<int> array;
    int HeapSize = 0;
};

void Solution::initArray()
{
    srand(time(nullptr));
    for (int i = 0; i < SequenceSize; i++)
    {
        array.push_back(rand() % RangeForRandom);
    }

    HeapSize = SequenceSize;
}

void Solution::print()
{
    for (auto i : array)
        std::cout << i << " ";
    std::cout << std::endl;
}

int Solution::PARENT(int i)
{
    return (i / 2);
}

int Solution::LEFT(int i)
{
    return (i << 1) + 1;
}

int Solution::RIGHT(int i)
{
    return ((i << 1) + 2);
}

void Solution::BuildMaxHeap()
{
    for (int i = (HeapSize / 2) - 1; i >= 0; --i)
    {
        ifDEBUGLOG() == true ? std::cout << "BUILDING MaxHeap ON :" << i << std::endl : std::cout << "";

        Heapify(i, HeapSize);
    }
}

// Heapify takes (node, it's reduced len as per heapSort len decrement)
// refer to for loop in heap sort
void Solution::Heapify(int i, int reduced_heap_len)
{
    int largest = i;
    int left = LEFT(i);
    int right = RIGHT(i);

    if (left < reduced_heap_len && array[left] > array[largest])
        largest = left;
    if (right < reduced_heap_len && array[right] > array[largest])
        largest = right;

    ifDEBUGLOG() == true ? std::cout << largest << " L-i " << i << std::endl : std::cout << "";

    if (largest != i)
    {
        // swap
        array[i] = array[i] ^ array[largest];
        array[largest] = array[i] ^ array[largest];
        array[i] = array[i] ^ array[largest];

        // further
        Heapify(largest, reduced_heap_len);
    }
}

void Solution::heapSort()
{
    BuildMaxHeap(); /* first */

    // taking root element, placing at back
    for (int i = HeapSize - 1; i >= 0; --i)
    {
        // push zero element to end
        array[i] = array[i] ^ array[0];
        array[0] = array[i] ^ array[0];
        array[i] = array[i] ^ array[0];

        // call at root again
        ifDEBUGLOG() == true ? std::cout << "heapifying root again with length :" << i << std::endl : std::cout << "";

        Heapify(0, i);
    }
}

int main(int argc, char **argv)
{
    Solution obj;

    if (argc == 2)
    {
        if ("true" == static_cast<std::string>(*(argv + 1)))
            obj.setDebugTrue();
    }

    obj.initArray();
    obj.print();

    obj.heapSort();
    obj.print();
}
