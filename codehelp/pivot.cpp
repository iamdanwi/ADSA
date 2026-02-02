#include <iostream>
#include <vector>
using namespace std;

int getPivot(vector<int> &nums)
{
    int s = 0, e = nums.size() - 1, mid = s + (e - s) / 2;

    while (s < e)
    {
        if (nums[mid] >= nums[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}

int main()
{
    vector<int> nums = {8, 10, 17, 1, 3};
    cout << "Pivot of this array is at index: " << getPivot(nums) << endl;
    return 0;
}