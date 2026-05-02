#include <iostream>
#include <vector>

using namespace std;

void subsets(const vector<int> &vec, vector<int> &curSubset, int &count, int idx)
{
    if (idx == vec.size())
    {
        count++;
        return;
    }

    // Include the current element.
    curSubset.push_back(vec[idx]);
    subsets(vec, curSubset, count, idx + 1);
    curSubset.pop_back();

    // Exclude the current element.
    subsets(vec, curSubset, count, idx + 1);
}

int find_subsets(const vector<int> &vec)
{
    vector<int> curSubset;
    int count = 0, idx = 0;
    subsets(vec, curSubset, count, idx);
    return count;
}

int main()
{
    vector<int> vec = {1, 2, 3};
    cout << "Total subsets = " << find_subsets(vec);

    return 0;
}
