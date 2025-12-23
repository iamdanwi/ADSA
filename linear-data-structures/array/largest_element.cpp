#include <iostream>

int largsetElement(int arr[], int n)
{
    int largest = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (largest < arr[i])
        {
            largest = arr[i];
        }
    }
    return largest;
}

int main()
{
    int nums[5] = {3, 2, 1, 5, 2};

    std::cout << "Largest element in the array is: " << largsetElement(nums, 5) << "\n";

    return 0;
}