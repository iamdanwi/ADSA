#include <iostream>
#include <vector>
using namespace std;

void find_subsets(vector<int> &nums, int idx, vector<int> &current_subset, vector<vector<int>> &all_subsets)
{

    if (idx == nums.size())
    {
        all_subsets.push_back(current_subset);
        return;
    }

    current_subset.push_back(nums[idx]);
    find_subsets(nums, idx + 1, current_subset, all_subsets);

    current_subset.pop_back();
    find_subsets(nums, idx + 1, current_subset, all_subsets);
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> all_sub;
    vector<int> curr_sub;
    find_subsets(nums, 0, curr_sub, all_sub);

    for (size_t i = 0; i < all_sub.size(); i++)
    {
        for (size_t j = 0; j < all_sub[i].size(); j++)
        {
            cout << all_sub[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}