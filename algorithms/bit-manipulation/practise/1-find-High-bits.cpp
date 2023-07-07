#include <iostream>
using namespace std;

int main()
{
  int number;
  cin >> number;

  // get the count of set bits in binary format
  cout << __builtin_popcount(number) << endl;

  return 0;
}
