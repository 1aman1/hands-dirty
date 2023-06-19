#include <iostream>
#include <algorithm>
#include <vector>
/*
ITERATIVE IMPLEMENTATION
*/

int binarySearch(std::vector<int> arr, int left, int right, int searchElement)
{
  while (right >= left)
  {
    int mid = left + (right - left) / 2;

    std::cout << "left " << left << " : "
              << "right " << right
              << std::endl;

    if (arr[mid] == searchElement)
      return mid;

    // If element is smaller than mid, then possibility reduces to left subarray
    if (searchElement < arr[mid])
      right = mid - 1;

    // If element is smaller than mid, then possibility reduces to right subarray
    if (arr[mid] < searchElement)
      left = mid + 1;
  }

  // We reach here when element is not present in array
  return -1;
}

int main()
{

  std::vector<int> array{10, 20, 30, 40, 60, 70};

  int search_item = 20;
  binarySearch(array, 0, array.size() - 1, search_item) != -1 ? std::cout << "found\n" : std::cout << "cant find\n";

  return 0;
}
