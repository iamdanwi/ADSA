#include <iostream>
#include <vector>

int findSecondHighest(std::vector<int> &arr)
{
    if (arr.size() < 2)
        return -1;
    int first = arr[0], second = INT_MIN;

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > first)
        {
            second = first;
            first = arr[i];
        }
        else if (arr[i] < first && arr[i] > second)
        {
            second = arr[i];
        }
    }
    return second;
}

int main()
{
    std::vector<int> arr = {12, 35, 1, 10, 34, 1};
    std::cout << "Second highest: " << findSecondHighest(arr) << std::endl;
    return 0;
}
