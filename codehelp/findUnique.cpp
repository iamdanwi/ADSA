#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findUnique(vector<int> &arr)
{
    unordered_map<int, int> freq;

    for (int n : arr)
    {
        freq[n]++;
    }

    for (auto &p : freq)
    {
        if (p.second == 1)
        {
            return p.first;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {2, 3, 1, 6, 3, 6, 2};
    cout << "Unique element in this array is: " << findUnique(nums) << endl;
    return 0;
}