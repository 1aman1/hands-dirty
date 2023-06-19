#include <iostream>
#include <algorithm>
#include <vector>
/*
RECURSIVE IMPLEMENTATION
*/

int binarySearch(const std::vector<int> &arr, int left, int right, const int &searchElement)
{
  if (right >= left)
  {
    int mid = left + (right - left) / 2;

    std::cout << "left " << left << " : "
              << "right " << right
              << std::endl;

    if (arr[mid] == searchElement)
      return mid;

    // If element is smaller than mid, then possibility reduces to left subarray
    if (arr[mid] > searchElement)
      return binarySearch(arr, left, mid - 1, searchElement);

    // If element is smaller than mid, then possibility reduces to right subarray
    return binarySearch(arr, mid + 1, right, searchElement);
  }

  // We reach here when element is not present in array
  // search negative
  return -1;
}

int main()
{
  std::vector<int> array{10, 20, 30, 40, 60, 70};

  int search_item = 20;

  binarySearch(array, 0, array.size(), search_item) != -1 ? std::cout << "found\n" : std::cout << "cant find\n";

  return 0;
}
