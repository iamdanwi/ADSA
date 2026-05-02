/*
Find two numbers in a unsorted array that add up to a target.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < numbers.size(); i++)
    {
        int needed = target - numbers[i];

        if (mp.count(needed))
        {
            return {mp[needed], i};
        }

        mp[numbers[i]] = i;
    }
    return {};
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {3, 2, 4};
    int target = 6;
    vector<int> idx = twoSum(nums, target);
    for (int i = 0; i < idx.size(); i++)
    {
        cout << idx[i] << " ";
    }
    cout << "\n";
    return 0;
}
