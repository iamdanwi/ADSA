#include <iostream>
#include <vector>

void subSet(std::vector<int> &current, std::vector<int> &nums, int idx)
{
    if (nums.size() == idx)
        return;

    current.push_back(nums[idx]);
    subSet(current, nums, idx + 1);
    current.pop_back();
    subSet(current, nums, idx + 1);
}

int main()
{
    std::vector<int> nums = {1, 2, 3};
    std::vector<int> current;
    subSet(current, nums, 0);
    // std::cout << "Subsets generated successfully." << std::endl;
    for (auto &i : current)
    {
        std::cout << i << " ";
    }

    return 0;
}