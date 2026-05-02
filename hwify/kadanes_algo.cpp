#include <iostream>
#include <vector>

using namespace std;

int bruteforce(vector<int> &nums)
{
    int n = nums.size();
    int prevSum = nums[0], curSum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                curSum += nums[k];
            }
            prevSum = max(prevSum, curSum);
            curSum = 0;
        }
    }
    return prevSum;
}

int optimized(vector<int> &nums)
{
    int n = nums.size();
    int prevSum = nums[0], curSum = 0;

    for (int i = 0; i < n; i++)
    {
        curSum = 0;
        for (int j = i; j < n; j++)
        {
            curSum += nums[j];
        }
        prevSum = max(prevSum, curSum);
    }
    return prevSum;
}

int kadanes_optimal(vector<int> &nums)
{
    int curSum = 0, max_sum = nums[0];
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        curSum += nums[i];

        max_sum = max(max_sum, curSum);

        if (curSum < 0)
        {
            curSum = 0;
        }
    }
    return max_sum;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {5, 4, -1, 7, 8};
    cout << "Max Sum = " << kadanes_optimal(nums) << endl;
    return 0;
}
