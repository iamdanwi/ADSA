#include <iostream>
#include <vector>

int maxProduct(std::vector<int> &nums)
{
    int maxSoFar = nums[0];
    int minSoFar = nums[0];
    int result = maxSoFar;

    for (int i = 1; i < nums.size(); i++)
    {
        int curr = nums[i];
        int tempMax = std::max({curr, maxSoFar * curr, minSoFar * curr});
        minSoFar = std::min({curr, maxSoFar * curr, minSoFar * curr});
        maxSoFar = tempMax;
        result = std::max(result, maxSoFar);
    }
    return result;
}

int main()
{
    std::vector<int> nums = {2, 3, -2, 4};
    std::cout << maxProduct(nums);
    return 0;
}
