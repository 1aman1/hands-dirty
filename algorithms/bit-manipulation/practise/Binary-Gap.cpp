// #include <bits/stdc++.h>
// #include <bit>
#include <bitset>
#include <algorithm>
#include <iostream>

using namespace std;

int maxGap(int number)
{
    if (__builtin_popcount(number) < 2)
        return 0;

    int result = -1;
    string str = std::bitset<32>(number).to_string();

    int left = __builtin_clz(number);
    int right = 1 + left;

    while (right < str.size())
    {
        if (str[right] == '1')
        {
            result = max(right - left - 1, result);
            left = right;
            right = 1 + left;
            continue;
        }
        ++right;
    }

    return result;
}

int main()
{
    // int number = 4;
    // int number = 9;
    int number = 15;
    // int number = 20;
    // int number = 529;
    // int number = 2147483647;

    cout << maxGap(number);

    return 0;
}