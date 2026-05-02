/*
Prefix Sum Array: Find the sum of elements in a given range [L, R] using a
prefix sum array.
*/

#include <iostream>
#include <vector>

using namespace std;

int sum(const vector<int> &nums, int l, int r)
{
    vector<int> prefixSum(nums.size());

    prefixSum[0] = nums[0];

    for (int i = 1; i < nums.size(); i++)
        prefixSum[i] = prefixSum[i - 1] + nums[i];

    if (l == 0)
        return prefixSum[r];

    return prefixSum[r] - prefixSum[l - 1];
}

int main(int argc, char const *argv[])
{
    vector<int> vec = {1, 2, 3, 4, 5};
    cout << sum(vec, 1, 2);
    return 0;
}
