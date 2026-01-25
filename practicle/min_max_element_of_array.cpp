#include <iostream>
#include <vector>

using namespace std;

// finding the smallest element in the array
int min_element(vector<int> &arr, int idx)
{

    if (idx == arr.size() - 1)
    {
        return arr[idx];
    }

    return min(min_element(arr, idx + 1), arr[idx]);
}

// finding the largest element in the array
int max_element(vector<int> &arr, int idx)
{
    if (idx == arr.size() - 1)
        return arr[idx];

    return max(max_element(arr, idx + 1), arr[idx]);
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {23, 56, 12, 3, 5};

    cout << "Smallest element in the arrya is: " << min_element(arr, 0);

    return 0;
}
