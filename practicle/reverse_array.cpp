#include <iostream>
#include <vector>

using namespace std;

void reverse_array(vector<int> &nums, int start, int end)
{
    if (start >= end)
        return;
    swap(nums[start], nums[end]);
    reverse_array(nums, start + 1, end - 1);
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {10, 20, 30, 40, 50};

    reverse_array(nums, 0, nums.size() - 1);

    for (size_t i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}
