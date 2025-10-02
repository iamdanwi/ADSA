#include <iostream>
#include <vector>

int findHighest(std::vector<int> &arr)
{
    if (arr.empty())
        return -1;
    int highest = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > highest)
            highest = arr[i];
    }
    return highest;
}

int main()
{
    std::vector<int> arr = {12, 35, 1, 10, 34, 1, 35};
    std::cout << "First highest: " << findHighest(arr) << std::endl;
    return 0;
}
