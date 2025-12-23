#include <iostream>
#include <vector>

void reverseArray(std::vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;

    std::swap(arr[start], arr[end]);

    reverseArray(arr, start + 1, end - 1);
}

int main()
{
    std::vector<int> nums = {1, 2, 3, 4, 5};

    reverseArray(nums, 0, nums.size() - 1);

    for (size_t i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << " ";
    }

    return 0;
}