#include <iostream>
#include <bitset>

using namespace std;

int Set_KthBit(int number, int Kth) { return (number | (1 << Kth)); }

int main()
{
    int number = 10;
    int Kth = 2;

    cout << number << ":" << bitset<8>(number) << " " << Kth << endl;

    number = Set_KthBit(number, Kth - 1);
    cout << number << ":" << bitset<8>(number) << endl;

    number = 16;
    Kth = 2;

    cout << number << ":" << bitset<8>(number) << " " << Kth << endl;

    number = Set_KthBit(number, Kth - 1);
    cout << number << ":" << bitset<8>(number) << endl;

    return 0;
}
