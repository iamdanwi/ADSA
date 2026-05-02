#include <iostream>
#include <vector>

using namespace std;

void buildComb(vector<vector<int>> &res, vector<int> &curComb, int n, int k, int i)
{
    if (curComb.size() == k)
    {
        res.push_back(curComb);
        return;
    }

    if (i > n || (curComb.size() + (n - i + 1) < k))
        return;

    curComb.push_back(i);
    buildComb(res, curComb, n, k, i + 1);
    curComb.pop_back();
    buildComb(res, curComb, n, k, i + 1);
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> res;
    vector<int> curComb;

    buildComb(res, curComb, n, k, 1);

    return res;
}

int main()
{
    vector<int> vec = {1, 2, 3};

    combine(4, 2);

    return 0;
}