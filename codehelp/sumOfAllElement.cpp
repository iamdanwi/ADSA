#include <iostream>
#include <vector>
using namespace std;

int sum(vector<int> &nums, int idx)
{
    if (nums.size() - 1 == idx)
        return nums[idx];
    return nums[idx] + sum(nums, idx + 1);
}

int main()
{
    vector<int> nums = {1, 2, 7, 4, 5, 6};
    cout << "Sum of all the elements is: " << sum(nums, 0);

    return 0;
}