#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void countSort(vector<int> &arr)
{
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;

    vector<int> count(range);

    for (int i = 0; i < arr.size(); i++)
        count[arr[i] - min]++;

    // cumulate the frequency
    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];

    // place the elements in order
    vector<int> output(arr.size());

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        output[count[arr[i] - min] - 1] = arr[i];
        // reduce the frequency in count array
        count[arr[i] - min]--;
    }

    arr.swap(output);
    output.resize(0);
}

void printArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    vector<int> arr = {1, 4, 1, 2, 7, 5, 2};
    countSort(arr);
    printArray(arr);
    return 0;
}