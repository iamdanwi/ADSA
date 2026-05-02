#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void plusMinus(vector<int> &nums)
{
    int n = nums.size();
    float pCount = 0.0, nCount = 0.0, zCount = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] >= 1)
        {
            pCount++;
        }
        else if (nums[i] < 0)
        {
            nCount++;
        }
        else
        {
            zCount++;
        }
    }
    cout << "Ratio of positive is: " << pCount / n << endl;
    cout << "Ratio of negative is: " << nCount / n << endl;
    cout << "Ratio of zero is: " << zCount / n << setprecision(6) << endl;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 1, 0, -1, -1};
    plusMinus(nums);
    return 0;
}
