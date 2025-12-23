#include <iostream>

int secondLargest(std::vector<int> &arr)
{
    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for (int x : arr)
    {
        if (x > largest)
        {
            secondLargest = largest;
            largest = x;
        }
        else if (x < largest && x > secondLargest)
        {
            secondLargest = x;
        }
    }

    return secondLargest;
}

int main()
{
    std::vector<int> nums = {3, 2, 1, 5, 5, 2};

    std::cout << "Second largest element in the array is: " << secondLargest(nums) << "\n";

    return 0;
}