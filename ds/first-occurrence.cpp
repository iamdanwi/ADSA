#include <iostream>
#include <vector>

using namespace std;

int find_frist_occurrence(vector<int> &nums, int target)
{
    int s = 0, e = nums.size() - 1, res = -1;

    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (nums[mid] == target)
        {
            res = mid;
            e = mid - 1;
        }
        else if (nums[mid] > target)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 3, 3, 4, 5};
    cout << "The frist occurrence is at: " << find_frist_occurrence(nums, 3) << endl;
    return 0;
}
