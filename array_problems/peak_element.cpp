#include <iostream>
#include <vector>

int findPeakElement(std::vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[mid + 1])
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int main()
{
    std::vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    std::cout << findPeakElement(nums);
    return 0;
}
