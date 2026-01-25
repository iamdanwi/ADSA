#include <iostream>
#include <vector>
using namespace std;

void reverse_array(vector<int> &arr, int l, int r)
{
    if (l >= r)
        return;

    swap(arr[l], arr[r]);
    reverse_array(arr, l + 1, r - 1);
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    reverse_array(nums, 0, nums.size() - 1);
    for (size_t i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}