#include <iostream>
#include <vector>

class NumArray
{
private:
    std::vector<int> prefix;

public:
    NumArray(std::vector<int> &nums)
    {
        prefix = std::vector<int>(nums.size());
        if (nums.size() > 0)
        {
            prefix[0] = nums[0];
            for (int i = 1; i < nums.size(); i++)
            {
                prefix[i] = prefix[i - 1] + nums[i];
            }
        }
    }

    int sumRange(int left, int right)
    {
        if (left == 0)
            return prefix[right];
        return prefix[right] - prefix[left - 1];
    }
};

int main()
{
    std::vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray *obj = new NumArray(nums);
    std::cout << obj->sumRange(0, 2) << "\n";
    std::cout << obj->sumRange(2, 5) << "\n";
    delete obj;
    return 0;
}
