#include <iostream>
#include <vector>

int findRotationCount(std::vector<int> &arr)
{
    int left = 0, right = arr.size() - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] > arr[right])
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int main()
{
    std::vector<int> arr = {7, 9, 11, 12, 5};
    std::cout << findRotationCount(arr);
    return 0;
}
