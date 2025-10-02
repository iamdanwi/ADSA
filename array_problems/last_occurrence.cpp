#include <iostream>
#include <vector>

int findLastOccurrence(std::vector<int> &arr, int target)
{
    int left = 0, right = arr.size() - 1;
    int result = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            result = mid;
            left = mid + 1;
        }
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return result;
}

int main()
{
    std::vector<int> arr = {1, 2, 2, 2, 3, 4, 4};
    std::cout << findLastOccurrence(arr, 2);
    return 0;
}
