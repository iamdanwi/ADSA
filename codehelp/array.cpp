#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int arr[4] = {24};
    fill(begin(arr), end(arr), 5);

    for (int x : arr)
        cout << x << " ";
    return 0;
}