#include <iostream>
#include <vector>

std::vector<int> generatePrefixSum(std::vector<int> &arr)
{
    std::vector<int> prefix(arr.size());
    prefix[0] = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    return prefix;
}

int main()
{
    std::vector<int> arr = {1, 2, 3, 4, 5};
    auto prefix = generatePrefixSum(arr);
    for (int val : prefix)
        std::cout << val << " ";
    return 0;
}
