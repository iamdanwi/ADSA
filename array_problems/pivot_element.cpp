#include <iostream>
#include <vector>

int findPivot(std::vector<int> &arr)
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
    return arr[left];
}

int main()
{
    std::vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    std::cout << findPivot(arr);
    return 0;
}
