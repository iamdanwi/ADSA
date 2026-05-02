#include <iostream>
#include <vector>

using namespace std;

void helper(vector<int> &nums, vector<int> &dp, int idx, int n)
{
    if (idx == n)
        return;

    dp[idx] = max(nums[idx] + dp[idx - 2], dp[idx - 1]);

    helper(nums, dp, idx + 1, n);
}

int rob(vector<int> &nums)
{
    int n = nums.size();

    if (n == 0)
        return 0;
    if (n == 1)
        return nums[0];

    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    helper(nums, dp, 2, n);

    return dp[n - 1];
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};

    cout << "max loot is: " << rob(nums) << endl;

    return 0;
}