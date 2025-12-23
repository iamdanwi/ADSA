#include <iostream>
#include <string>
#include <vector>

// A program to check if s2 is a subsequence of s1 using
// Longest Common Subsequence (LCS) approach
// leetcode link: https://leetcode.com/problems/longest-common-subsequence/

// Space optimized function to check longest common subsequence
int checkSpaceOpti(std::string &s1, std::string &s2, int n, int m)
{

    if (n < m)
        return checkSpaceOpti(s2, s1, m, n);
    std::vector<int> prev(m + 1, 0);
    std::vector<int> curr(m + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                curr[j] = 1 + prev[j - 1];
            }
            else
            {
                curr[j] = std::max(prev[j], curr[j - 1]);
            }
        }
        prev = curr;
    }

    return prev[m];
}

// Function to check longest common subsequence using tabulation
int checkTabu(std::string &s1, std::string &s2, int n, int m)
{
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

// recursive approach with memoization
int checkMemo(std::string &s1, std::string &s2, int n, int m, std::vector<std::vector<int>> &memo)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }

    if (memo[n][m] != -1)
    {
        return memo[n][m];
    }

    if (s1[n - 1] == s2[m - 1])
    {
        return memo[n][m] = 1 + checkMemo(s1, s2, n - 1, m - 1, memo);
    }
    else
    {
        return memo[n][m] = std::max(checkMemo(s1, s2, n - 1, m, memo), checkMemo(s1, s2, n, m - 1, memo));
    }
}

// recursive approach without memoization
int check(std::string s1, std::string s2, int n, int m)
{
    if (n == 0 || m == 0)
        return 0;

    if (s1[n - 1] == s2[m - 1])
        return 1 + check(s1, s2, n - 1, m - 1);

    return std::max(check(s1, s2, n - 1, m), check(s1, s2, n, m - 1));
}

// function to check if s2 is a subsequence of s1
std::string isSubsequence(std::string s1, std::string s2)
{
    int n = s1.length();
    int m = s2.length();
    // std::vector<std::vector<int>> memo(n + 1, std::vector<int>(m + 1, -1));

    if (checkSpaceOpti(s1, s2, n, m) >= 1)
        return "YES\n";
    else
        return "NO\n";
}

int main()
{
    std::string s1 = "axyz", s2 = "baz";
    std::cout << isSubsequence(s1, s2);
    return 0;
}
