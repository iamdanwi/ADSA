#include <iostream>
#include <vector>

int majorityElement(std::vector<int> &nums)
{
    int count = 0;
    int candidate = 0;

    for (int num : nums)
    {
        if (count == 0)
        {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }
    return candidate;
}

int main()
{
    std::vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    std::cout << majorityElement(nums);
    return 0;
}
