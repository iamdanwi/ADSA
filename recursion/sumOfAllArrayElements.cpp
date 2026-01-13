#include <iostream>
#include <vector>

int sumOfAllElemetns(std::vector<int> arr, int idx)
{
    if (idx < 0)
        return 0;

    return arr[idx] + sumOfAllElemetns(arr, idx - 1);
}

int main()
{
    std::vector<int> nums = {1, 2, 3, 4, 5};

    std::cout << sumOfAllElemetns(nums, nums.size() - 1);

    return 0;
}