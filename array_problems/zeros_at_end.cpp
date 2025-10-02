#include <iostream>
#include <vector>

void moveZerosToEnd(std::vector<int> &arr)
{
    int nonZero = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            std::swap(arr[nonZero], arr[i]);
            nonZero++;
        }
    }
}

int main()
{
    std::vector<int> arr = {1, 0, 2, 0, 0, 3, 4};
    moveZerosToEnd(arr);
    for (int num : arr)
        std::cout << num << " ";
    return 0;
}
