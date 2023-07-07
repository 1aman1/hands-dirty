#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    int a = 25;

    cout << "a " << a << " " << bitset<8>(a) << endl;
    a = a >> 1;
    cout << "a " << a << " " << bitset<8>(a) << endl;

    return 0;
}