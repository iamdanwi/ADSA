#include <iostream>
#include <vector>

int findKthMissing(std::vector<int> &arr, int k)
{
    int left = 0, right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int missing = arr[mid] - (mid + 1);

        if (missing < k)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left + k;
}

int main()
{
    std::vector<int> arr = {2, 3, 4, 7, 11};
    std::cout << findKthMissing(arr, 5);
    return 0;
}
