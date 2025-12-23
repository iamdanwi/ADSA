#include <iostream>

void printTheArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void insertElement(int arr[], int &n, int capacity, int ele, int pos)
{
    if (n >= capacity || pos < 0 || pos > n)
    {
        std::cout << "Insertion not possible" << std::endl;
        return;
    }

    for (int i = n; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = ele;
    n++;
}

void updateElement(int arr[], int n, int pos, int val)
{
    if (pos >= 0 && pos < n)
    {
        arr[pos] = val;
    }
    else
    {
        std::cout << "Invalid Index" << std::endl;
    }
}

void deleteAnElement(int arr[], int &n, int ele)
{
    int foundIndex = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele)
        {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1)
    {
        std::cout << "Element not found!" << std::endl;
        return;
    }

    for (int j = foundIndex; j < n - 1; j++)
    {
        arr[j] = arr[j + 1];
    }

    n--;
}

int main()
{
    int nums[100] = {10, 20, 30, 40, 50, 60};
    int n = 6;
    int capacity = 100;

    std::cout << "1. READ (Initial Array): \n";
    printTheArray(nums, n);

    std::cout << "\n2. CREATE (Insert 99 at index 2): \n";
    insertElement(nums, n, capacity, 99, 2);
    printTheArray(nums, n);

    std::cout << "\n3. UPDATE (Change index 0 to 888): \n";
    updateElement(nums, n, 0, 888);
    printTheArray(nums, n);

    std::cout << "\n4. DELETE (Remove element 30): \n";
    deleteAnElement(nums, n, 30);
    printTheArray(nums, n);

    return 0;
}