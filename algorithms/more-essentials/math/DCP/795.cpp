// This problem was asked by Square.

// Assume you have access to a function toss_biased() which returns 0 or 1 with a probability that's not 50-50 (but also not 0-100 or 100-0). You do not know the bias of the coin.

// Write a function to simulate an unbiased coin toss.

#include <iostream>
#include <cstdlib>
#include <ctime>

int toss_biased()
{
  return rand() % 100 < 70 ? 1 : 0; // 70% chance of 1
}

// Unbiased coin toss using the biased coin
int toss_unbiased()
{
  while (true)
  {
    int first = toss_biased();
    int second = toss_biased();

    if (first == 0 && second == 1)
      return 0;
    else if (first == 1 && second == 0)
      return 1;
    // If the results are the same, repeat the process
  }
}

int main()
{
  srand(static_cast<unsigned int>(time(0))); // Seed for randomness

  int countZero = 0, countOne = 0;

  // Test unbiased toss
  for (int i = 0; i < 100000; ++i)
  {
    int result = toss_unbiased();
    if (result == 0)
    {
      countZero++;
    }
    else
    {
      countOne++;
    }
  }

  std::cout << "Number of 0s: " << countZero << std::endl;
  std::cout << "Number of 1s: " << countOne << std::endl;

  return 0;
}
