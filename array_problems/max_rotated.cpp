#include <iostream>
#include <vector>

int findMax(std::vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right])
            left = mid;
        else
            right = mid - 1;
    }
    return nums[left];
}

int main()
{
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    std::cout << findMax(nums);
    return 0;
}
