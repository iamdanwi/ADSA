#include <iostream>
#include <vector>

using namespace std;

void find_permute(vector<vector<int>> &res, vector<int> &curSub, vector<bool> &used, vector<int> &nums, int i, int pos)
{

    if (curSub.size() == nums.size())
    {
        res.push_back(curSub);
        return;
    }

    curSub.push_back(nums[i]);
    used[i] = true;
    find_permute(res, curSub, used, nums, 0, pos + 1);

    curSub.pop_back();
    used[i] = false;
    find_permute(res, curSub, used, nums, i + 1, pos);
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<bool> used(nums.size(), false);
    vector<int> curSub;

    find_permute(res, curSub, used, nums, 0, 0);

    return res;
}
int main()
{
    vector<int> vec = {1, 2, 3};

    return 0;
}