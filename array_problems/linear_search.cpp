#include <iostream>
#include <vector>

int linearSearch(std::vector<int> &arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int main()
{
    std::vector<int> arr = {1, 3, 5, 7, 9, 11};
    std::cout << linearSearch(arr, 7);
    return 0;
}
