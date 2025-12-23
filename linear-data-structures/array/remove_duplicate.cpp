#include <iostream>

int removeDuplicates(std::vector<int> &nums)
{
    if (nums.empty())
        return 0;

    sort(nums.begin(), nums.end());

    int k = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1])
        {
            nums[k++] = nums[i];
        }
    }
    return k;
}

void printTheArray(std::vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> nums = {1, 2, 2, 4, 4, 6, 7, 6, 9};

    removeDuplicates(nums);
    printTheArray(nums);

    return 0;
}