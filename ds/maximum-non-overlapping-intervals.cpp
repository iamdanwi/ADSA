#include <iostream>
#include <vector>

using namespace std;

void print_matrix(vector<vector<int>> &meetings)
{

    for (size_t i = 0; i < meetings.size(); i++)
    {
        for (size_t j = 0; j < meetings[i].size(); j++)
        {
            cout << meetings[i][j] << endl;
        }
    }
}

bool compare_by_end_time(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}

int maximize_non_overlapping_meetings(vector<vector<int>> meetings)
{
    if (meetings.empty())
    {
        return 0;
    }

    sort(meetings.begin(), meetings.end(), compare_by_end_time);

    int count = 1;

    int current_end_time = meetings[0][1];

    for (size_t i = 0; i < meetings.size(); i++)
    {
        if (meetings[i][0] >= current_end_time)
        {
            count++;
            current_end_time = meetings[i][1];
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> vec = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    // print_matrix(vec);
    cout << maximize_non_overlapping_meetings(vec);
    return 0;
}
