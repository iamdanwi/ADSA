/*
Equilibrium Index: Find an index in an array such that the sum of elements to
the left is equal to the sum of elements to the right.
*/

#include <iostream>
#include <vector>
#include <numeric>

int findEquilibrium(const std::vector<int> &nums)
{
    int prefSum = 0, total;

    total = std::accumulate(nums.begin(), nums.end(), 0);
    std::cout << "total: " << total << std::endl;

    for (int i = 0; i < nums.size(); i++)
    {
        int suffSum = total - prefSum - nums[i];
        if (prefSum == suffSum)
        {
            return i;
        }
        prefSum += nums[i];
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    std::vector<int> nums = {1, 2, 0, 3};
    std::cout << "The index is: " << findEquilibrium(nums) << std::endl;
    return 0;
}
