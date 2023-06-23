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
	// mid element is pivot
	int i = left, j = right, pivot = left + (right - left) / 2;
	while (i <= j)
	{
		while (array[i] < pivot)
			++i;
		while (array[j] > pivot)
			--j;
		if (i < j)
		{
			int tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			++i;
			--j;
		}
	}
	if (left < j)
		quicksort(left, j);
	if (i < right)
		quicksort(i, right);
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
