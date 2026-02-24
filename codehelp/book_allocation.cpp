#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

bool isPossible(vector<int> &books, int n, int m, int mid)
{
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (pageSum + books[i] <= mid)
        {
            pageSum += books[i];
        }
        else
        {
            studentCount++;
            if (studentCount > m || books[i] > mid)
            {
                return false;
            }
            pageSum = books[i];
        }
    }
    return true;
}

int allocateBooks(vector<int> &books, int n, int m)
{
    if (m > n)
    {
        return -1;
    }
    int s = *max_element(books.begin(), books.end());
    int e = accumulate(books.begin(), books.end(), 0);

    int mid = s + (e - s) / 2;
    int ans = -1;

    while (s <= e)
    {
        if (isPossible(books, n, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> books = {25, 46, 28, 49, 24};
    int n = 5, m = 4;
    cout << "Minimum number of pages ares: " << allocateBooks(books, n, m) << endl;
    return 0;
}
