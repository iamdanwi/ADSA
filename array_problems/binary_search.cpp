#include <iostream>
#include <vector>

int binarySearch(std::vector<int> &arr, int target)
{
    int left = 0, right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << binarySearch(arr, 5);
    return 0;
}
