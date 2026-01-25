#include <iostream>
#include <vector>
using namespace std;

int sum(vector<int> &arr, int idx)
{
    if (idx == arr.size())
        return 0;

    return sum(arr, idx + 1) + arr[idx];
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << sum(nums, 0);
    return 0;
}