#include <iostream>
#include <bitset>

int Set_KthBit_As_Target(int number, int Kth, int target)
{
    int mask = ~(1 << Kth);
    return ((number & mask) | (target << Kth));
}

int main()
{
    int number = 3;
    int Kth = 4;
    int target = 1;

    std::cout << number << ":" << std::bitset<8>(number) << " " << Kth << std::endl;
    number = Set_KthBit_As_Target(number, Kth - 1, target);
    std::cout << number << ":" << std::bitset<8>(number) << std::endl;

    number = 15;
    Kth = 3;
    target = 0;

    std::cout << number << ":" << std::bitset<8>(number) << " " << Kth << std::endl;
    number = Set_KthBit_As_Target(number, Kth - 1, target);
    std::cout << number << ":" << std::bitset<8>(number) << std::endl;

    return 0;
}
