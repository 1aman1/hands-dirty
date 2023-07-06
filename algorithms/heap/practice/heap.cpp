#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

constexpr int RANDOM_RANGE = 200;
constexpr int SIZE = 12;

class Container
{
protected:
    std::vector<int> heapTub;
    int size = 0;

public:
    Container(int len)
    {
        heapTub.resize(len);
        size = len;

        srand(time(nullptr));
        std::generate(heapTub.begin(), heapTub.end(),
                      []()
                      { return rand() % RANDOM_RANGE; });
    }

    void printBuffer()
    {
        std::cout << "\n->: ";
        for (const auto &itr : heapTub)
            std::cout << itr << " : ";
    }
};

// Heap implementation
class Heap : public Container
{
public:
    Heap(int x) : Container(x) {}
    void Heapify(int, int);
    void Build_Heap();
    void Heap_Sort();

public: // additional operations
    void Push(int);
    int Pop();
    bool Is_Heap();
};

void Heap::Heapify(int index, int heapLen)
{
    int leftChild = index * 2 + 1;
    int rightChild = index * 2 + 2;
    int largest = index;

    if (leftChild < heapLen && heapTub[leftChild] > heapTub[largest])
        largest = leftChild;

    if (rightChild < heapLen && heapTub[rightChild] > heapTub[largest])
        largest = rightChild;

    if (largest != index)
    {
        std::swap(heapTub[largest], heapTub[index]);

        Heapify(largest, heapLen);
    }
}

void Heap::Build_Heap()
{
    // std::cout << "\nBuilding Heap";
    for (int i = Container::size / 2 - 1; i >= 0; --i)
    {
        Heapify(i, Container::size);
    }
}

void Heap::Heap_Sort()
{
    Build_Heap();

    for (int i = Container::size - 1; i > 0; --i)
    {
        std::swap(heapTub[i], heapTub[0]);
        Heapify(0, i);
    }
}

bool Heap::Is_Heap()
{
    for (auto i = 0; i < Container::size / 2; ++i)
    {
        int leftChild = i * 2 + 1, right = i * 2 + 2;

        if ((heapTub[leftChild] > heapTub[i]) ||
            (right < Container::size && heapTub[right] > heapTub[i]))
            return false;
    }

    return true;
}

int Heap::Pop()
{
    int heapTop = heapTub.front();
    std::swap(heapTub.front(), heapTub.back());
    heapTub.pop_back();
    --Container::size;
    Build_Heap();

    return heapTop;
}

void Heap::Push(int newValue)
{
    heapTub.push_back(newValue);
    ++Container::size;

    Build_Heap();
}

int main()
{
    Heap obj(SIZE);

    std::cout << "\nDefault sequence: ";
    obj.printBuffer();
    std::cout << "\nis Heap ? " << std::boolalpha << obj.Is_Heap();

    obj.Build_Heap();
    obj.printBuffer();
    std::cout << "\nis Heap ? " << std::boolalpha << obj.Is_Heap();

    obj.Heap_Sort();
    obj.printBuffer();
    std::cout << "\nis Heap ? " << std::boolalpha << obj.Is_Heap();

    // obj.Push(500);
    // obj.printBuffer();

    // std::cout << "\nPopped: " << obj.Pop();
    // obj.printBuffer();
    // std::cout << "\nis Heap ? " << std::boolalpha << obj.Is_Heap();

    // obj.Push(1000);
    // obj.printBuffer();
    // std::cout << "\nis Heap ? " << std::boolalpha << obj.Is_Heap();

    std::cout << std::endl;
    return 0;
}