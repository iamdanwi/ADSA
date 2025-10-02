#include <iostream>
#include <vector>

std::vector<int> findLeaders(std::vector<int> &arr)
{
    std::vector<int> leaders;
    int maxRight = arr.back();
    leaders.push_back(maxRight);

    for (int i = arr.size() - 2; i >= 0; i--)
    {
        if (arr[i] > maxRight)
        {
            maxRight = arr[i];
            leaders.push_back(maxRight);
        }
    }
    return leaders;
}

int main()
{
    std::vector<int> arr = {16, 17, 4, 3, 5, 2};
    std::vector<int> leaders = findLeaders(arr);
    for (int leader : leaders)
    {
        std::cout << leader << " ";
    }
    return 0;
}
