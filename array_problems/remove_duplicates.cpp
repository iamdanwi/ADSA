#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int> &nums)
{
    if (nums.empty())
        return 0;
    int k = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1])
        {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

int main()
{
    std::vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};
    int k = removeDuplicates(nums);
    for (int i = 0; i < k; i++)
    {
        std::cout << nums[i] << " ";
    }
    return 0;
}
