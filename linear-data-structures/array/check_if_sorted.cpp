#include <iostream>

bool isSorted(std::vector<int> &nums)
{
    if (nums.size() < 2)
        return true;

    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    std::cout << "Array is " << (isSorted(nums) ? "" : "not") << " sorted\n";

    return 0;
}