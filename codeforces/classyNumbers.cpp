#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long dp[20][5][2];
string S;

// Recursive DP function with memoization
long long solve_dp(int idx, int cnt, bool tight)
{
    // If we have used more than 3 non-zero digits, this path is invalid
    if (cnt > 3)
        return 0;

    // If we have placed all digits, we found 1 valid number
    if (idx == S.size())
        return 1;

    // Return memoized result if available
    // Note: We only memoize when tight constraint is false because strict
    // constraints usually depend on the specific prefix of N.
    // However, for simplicity and small state space, we can memoize everything
    // or just memoize when !tight. Here we memoize all valid states.
    if (dp[idx][cnt][tight] != -1)
        return dp[idx][cnt][tight];

    long long ans = 0;
    int limit = tight ? (S[idx] - '0') : 9;

    for (int digit = 0; digit <= limit; digit++)
    {
        // Calculate new tight constraint
        bool next_tight = tight && (digit == limit);

        // Calculate new non-zero count
        int next_cnt = cnt + (digit > 0 ? 1 : 0);

        // Recursively call for the next position
        ans += solve_dp(idx + 1, next_cnt, next_tight);
    }

    return dp[idx][cnt][tight] = ans;
}

long long calc(long long n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1; // 0 has 0 non-zero digits, which is <= 3

    S = to_string(n);
    // Initialize DP table with -1
    memset(dp, -1, sizeof(dp));

    // The DP counts numbers with equal length to n (including leading zeros if we viewed it that way,
    // but the standard tight constraint logic handles 0..N naturally).
    // This logic actually counts 0 as a valid number (empty non-zero digits).
    // The problem usually asks for range [L, R], and 0 isn't positive, but L >= 1 in constraints usually.
    // If L, R >= 1, the number 0 won't be in the final count if we do solve(R) - solve(L-1) properly.

    return solve_dp(0, 0, true);
}

int main()
{
    int T;
    if (cin >> T)
    {
        while (T--)
        {
            long long L, R;
            cin >> L >> R;
            // calc(R) includes 0..R
            // calc(L-1) includes 0..L-1
            // The difference gives numbers in [L, R]
            // Note: calc returns 1 extra for '0' itself, but it cancels out.
            cout << calc(R) - calc(L - 1) << endl;
        }
    }
    return 0;
}