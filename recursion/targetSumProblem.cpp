#include <iostream>
#include <vector>

int countWays(int index, int currentSum, int target, std::vector<int> &nums)
{
    if (index == nums.size())
    {
        if (currentSum == target)
            return 1;
        else
            return 0;
    }

    int pick = countWays(index + 1, currentSum += nums[index], target, nums);

    int dontPick = countWays(index + 1, currentSum, target, nums);

    return pick + dontPick;
}

int main()
{
    std::vector<int> nums = {1, 2, 3, 4, 5, 6};
    std::cout << "number of ways to make the target sum is: " << countWays(0, 0, 5, nums);
    return 0;
}