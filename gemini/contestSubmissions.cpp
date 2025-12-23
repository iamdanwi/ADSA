#include <iostream>
#include <algorithm>
#include <vector>

struct Submissions
{
    int time_taken;
    int penalty;
};

bool compareSubmissions(const Submissions &a, const Submissions &b)
{
    // Priority 1: Penalty (Lower is better)
    if (a.penalty != b.penalty)
    {
        // Return true if 'a' should come before 'b'
        return a.penalty < b.penalty;
    }

    // Priority 2: Tie-breaker - Time Taken (Lower is better)
    // We only reach here if penalties are exactly equal
    return a.time_taken < b.time_taken;
}

int main()
{
    std::vector<Submissions> submissions = {{12, 3}, {12, 0}, {15, 0}};
    std::cout << "Before sorting time taken: " << submissions[0].time_taken;
    std::sort(submissions.begin(), submissions.end(), compareSubmissions);
    std::cout << "After sorting time taken: " << submissions[0].time_taken;
    return 0;
}