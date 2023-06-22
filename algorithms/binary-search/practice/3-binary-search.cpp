#include <iostream>
#include <algorithm>
#include <vector>
/*
RECURSIVE IMPLEMENTATION
*/

#define DEBUGLOG true

bool linear_search_solution1(std::vector<int> &array, int item)
{
  for (int i : array)
  {
    if (i == item)
      return true;

    DEBUGLOG == true ? std::cout << "not found yet\n" : std::cout << std::endl;
  }
  return false;
}

bool linear_search_solution2(const std::vector<int> &array, int item)
{
  for (auto left = array.begin(), right = array.end(); left < right;)
  {
    if (*left == item)
    {
      return true;
    }
    if (*right == item)
    {
      return true;
    }
    ++left;
    --right;

    DEBUGLOG == true ? std::cout << "not found yet\n" : std::cout << std::endl;
  }
  return false;
}

int main()
{
  std::vector<int> array{10, 20, 30, 40, 60, 70, 80, 90, 100};

  int search_item = 50;
  if (linear_search_solution2(array, search_item))
    std::cout << "found\n";
  else
    std::cout << "not found\n";

  return 0;
}
