#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool isPossible(vector<int> &boards, int k, int mid)
{
    int painter = 1;
    int boardSum = 0;

    for (int i = 0; i < boards.size(); i++)
    {
        if (boardSum + boards[i] <= mid)
        {
            boardSum += boards[i];
        }
        else
        {
            painter++;
            if (painter > k || boards[i] > mid)
            {
                return false;
            }
            boardSum = boards[i];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int n = boards.size();
    int s = *max_element(boards.begin(), boards.end());
    int e = accumulate(boards.begin(), boards.end(), 0);

    int mid = s + (e - s) / 2;
    int ans;

    while (s <= e)
    {
        if (isPossible(boards, k, mid))
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

int main()
{
    vector<int> boards = {2, 1, 5, 6, 2, 3};
    int k = 2;

    cout << "Unite of time required " << findLargestMinDistance(boards, k) << endl;

    return 0;
}