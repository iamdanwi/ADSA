#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int> &nums)
{
    if (nums.size() <= 2)
        return nums.size();
    int k = 2;
    for (int i = 2; i < nums.size(); i++)
    {
        if (nums[i] != nums[k - 2])
        {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

int main()
{
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = removeDuplicates(nums);
    for (int i = 0; i < k; i++)
    {
        std::cout << nums[i] << " ";
    }
    return 0;
}
