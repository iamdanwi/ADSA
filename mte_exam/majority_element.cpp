#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int> &nums)
{
    int cnt = 0, el;

    for (int num : nums)
    {
        if (cnt == 0)
        {
            cnt = 1;
            el = num;
        }
        else if (el == num)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }

    cnt = 0;
    for (int num : nums)
    {
        if (el == num)
            cnt++;
    }

    if (cnt > (nums.size() / 2))
        return el;

    return -1;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << "Majority element is: " << majorityElement(nums) << endl;
    return 0;
}
