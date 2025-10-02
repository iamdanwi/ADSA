#include <iostream>
#include <vector>

std::vector<int> generateSuffixSum(std::vector<int> &arr)
{
    int n = arr.size();
    std::vector<int> suffix(n);
    suffix[n - 1] = arr[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = suffix[i + 1] + arr[i];
    }
    return suffix;
}

int main()
{
    std::vector<int> arr = {1, 2, 3, 4, 5};
    auto suffix = generateSuffixSum(arr);
    for (int val : suffix)
        std::cout << val << " ";
    return 0;
}
