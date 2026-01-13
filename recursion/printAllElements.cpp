#include <iostream>
#include <vector>

void printAllElements(int idx, std::vector<int> &nums)
{
    if (idx < 0)
    {
        return;
    }
    std::cout << nums[idx] << " ";
    printAllElements(idx - 1, nums);
}

int main()
{
    std::vector<int> nums = {1, 2, 3, 4, 5};

    printAllElements(nums.size() - 1, nums);

    return 0;
}