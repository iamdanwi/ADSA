#include <iostream>
#include <vector>
using namespace std;

int max_element(vector<int> &arr, int idx)
{
    if (idx == arr.size() - 1)
        return arr[idx];

    return max(max_element(arr, idx + 1), arr[idx]);
}

int main()
{
    vector<int> nums = {12, 54, 16, 23, 523, 4};
    cout << max_element(nums, 0);
    return 0;
}