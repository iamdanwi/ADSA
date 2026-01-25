#include <iostream>
#include <vector>
using namespace std;

int min_element(vector<int> &nums, int idx)
{

    if (idx == nums.size() - 1)
    {
        return nums[idx];
    }
    return min(min_element(nums, idx + 1), nums[idx]);
}

int main()
{
    vector<int> arr = {12, 54, 1, 23, 523, 4};
    cout << min_element(arr, 0);
    return 0;
}