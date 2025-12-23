#include <iostream>
#include <algorithm>

int main()
{
    std::vector<int> nums = {10, 20, 40, 50};

    auto it = std::lower_bound(nums.begin(), nums.end(), 30);
    int index = std::distance(nums.begin(), it);

    std::cout << "the index of the 30 will be: " << index << "\n";

    return 0;
}