#include <iostream>
#include <bitset>

using namespace std;

bool Is_KthBit_Set_method1(int number, int Kth) { return (number >> Kth) & 1; }

bool Is_KthBit_Set_method2(int number, int Kth) { return (number & (1 << Kth)); }

int main()
{
    int number = 10;
    int Kth = 2;

    cout << bitset<8>(number) << " " << Kth << endl;

    Is_KthBit_Set_method1(number, Kth - 1) ? cout << "Yes\n" : cout << "No\n";
    Is_KthBit_Set_method2(number, Kth - 1) ? cout << "Yes\n" : cout << "No\n";

    number = 16;
    Kth = 2;

    cout << bitset<8>(number) << " " << Kth << endl;

    Is_KthBit_Set_method1(number, Kth - 1) ? cout << "Yes\n" : cout << "No\n";
    Is_KthBit_Set_method2(number, Kth - 1) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}
