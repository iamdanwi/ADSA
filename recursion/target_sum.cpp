#include <iostream>
#include <vector>
using namespace std;

void target_sum_subsets(vector<int> &nums, int idx, int target, vector<int> &curr_sub, vector<vector<int>> &all_sub)
{
    if (target == 0)
    {
        all_sub.push_back(curr_sub);
        return;
    }
    if (idx == nums.size() || target < 0)
        return;

    curr_sub.push_back(nums[idx]);
    target_sum_subsets(nums, idx + 1, target - nums[idx], curr_sub, all_sub);

    curr_sub.pop_back();
    target_sum_subsets(nums, idx + 1, target, curr_sub, all_sub);
}

int main()
{
    vector<int> arr = {2, 3, 5, 6, 8};
    vector<int> current_subset;
    vector<vector<int>> all_subsets;
    target_sum_subsets(arr, 0, 10, current_subset, all_subsets);
    for (size_t i = 0; i < all_subsets.size(); i++)
    {
        for (size_t j = 0; j < all_subsets[i].size(); j++)
        {
            cout << all_subsets[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}