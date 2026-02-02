#include <iostream>
#include <vector>
using namespace std;

int minEle(vector<int> &nums, int idx)
{
    if (nums.size() - 1 == idx)
        return nums[idx];

    return min(minEle(nums, idx + 1), nums[idx]);
}

int maxEle(vector<int> nums, int idx)
{
    if (nums.size() - 1 == idx)
        return nums[idx];
    return max(maxEle(nums, idx + 1), nums[idx]);
}

int main()
{
    vector<int> arr = {1, 24, 5, -1, 6, 0};
    cout << "Minimum elment in the array is: " << minEle(arr, 0) << endl;
    cout << "Maximum elment in the array is: " << maxEle(arr, 0) << endl;
    return 0;
}