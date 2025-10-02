#include <iostream>
#include <vector>

int findTotalOccurrences(std::vector<int> &arr, int target)
{
    int first = -1, last = -1;
    int left = 0, right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            first = mid;
            right = mid - 1;
        }
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    left = 0;
    right = arr.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            last = mid;
            left = mid + 1;
        }
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    if (first == -1)
        return 0;
    return last - first + 1;
}

int main()
{
    std::vector<int> arr = {1, 2, 2, 2, 3, 4, 4};
    std::cout << findTotalOccurrences(arr, 2);
    return 0;
}
