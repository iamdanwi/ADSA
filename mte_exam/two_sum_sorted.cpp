/*
Find two numbers in a sorted array that add up to a target.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    int left = 0;
    int right = numbers.size() - 1;

    while (left < right)
    {
        int total = numbers[left] + numbers[right];

        if (total == target)
        {
            return {left + 1, right + 1};
        }
        else if (target < total)
        {
            right--;
        }
        else
        {
            left++;
        }
    }
    return {-1, -1};
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {-1, 0};
    int target = -1;
    vector<int> idx = twoSum(nums, target);
    for (int i = 0; i < idx.size(); i++)
    {
        cout << idx[i] << " ";
    }
    cout << "\n";
    return 0;
}
