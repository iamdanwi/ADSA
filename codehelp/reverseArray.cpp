#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int> &nums, int l, int r)
{
    if (l >= r)
        return;
    swap(nums[l], nums[r]);
    reverseArray(nums, l + 1, r - 1);
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    reverseArray(nums, 0, nums.size() - 1);
    for (auto num : nums)
    {
        cout << num << " ";
    }
    cout << "\n";
    return 0;
}