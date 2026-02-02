#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

int kthSmallest(int arr[], int low, int high, int k)
{
    if (low <= high)
    {
        int p = partition(arr, low, high);

        if (p == k - 1)
            return arr[p];
        else if (p > k - 1)
            return kthSmallest(arr, low, p - 1, k);
        else
            return kthSmallest(arr, p + 1, high, k);
    }
    return -1;
}

int kthLargest(int arr[], int low, int high, int k)
{
    if (low <= high)
    {
        int p = partition(arr, low, high);

        int targetIndex = high - k + 1;

        if (p == targetIndex)
            return arr[p];
        else if (p < targetIndex)
            return kthLargest(arr, p + 1, high, k);
        else
            return kthLargest(arr, low, p - 1, k);
    }
    return -1;
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    cout << "Kth smallest element: " << kthSmallest(arr, 0, n - 1, k) << endl;
    cout << "Kth largest element: " << kthLargest(arr, 0, n - 1, k) << endl;
    return 0;
}
