#include <iostream>
#include <unordered_map>

using namespace std;

// map
bool isUnique(std::string str)
{
    // two pointer approach
    for (int i = 0; i < str.size() - 1; ++i)
    {
        for (int j = i + 1; j < str.size() - 1; ++j)
        {
            if (str[i] == str[j])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    std::string str1 = "aman";
    std::string str2 = "gupta";

    std::cout << std::boolalpha << isUnique(str1) << std::endl;
    std::cout << std::boolalpha << isUnique(str2) << std::endl;

    return 0;
}
