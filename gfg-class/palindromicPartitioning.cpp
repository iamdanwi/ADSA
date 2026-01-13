#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    // 1. Pass memo by reference (&memo) to avoid copying it every recursion
    int palindromePartition(string &s, int i, int j, vector<vector<int>> &memo)
    {

        // Base Case 1: If empty or single char, 0 cuts needed
        if (i >= j)
        {
            return 0;
        }

        // Check memo
        if (memo[i][j] != -1)
        {
            return memo[i][j];
        }

        // Base Case 2: If the substring is already a palindrome, 0 cuts needed
        if (isPalindrome(s, i, j))
        {
            return memo[i][j] = 0;
        }

        int res = INT_MAX;

        // Loop from i to j-1
        for (int k = i; k < j; k++)
        {

            // 2. Optimization: We only check cuts if the LEFT part is a palindrome.
            // This reduces unnecessary recursion. If s[i...k] is palindrome,
            // we take 1 cut + cost of right half.
            /* Note: The standard MCM recurrence is:
               1 + solve(i, k) + solve(k+1, j)
               But for Palindrome Partitioning, checking isPalindrome(i, k) is faster.
            */

            int cuts;

            // Standard MCM Logic Approach (Safe & General)
            // We calculate cost of left part + cost of right part + 1 cut

            int left = memo[i][k] != -1 ? memo[i][k] : palindromePartition(s, i, k, memo);
            int right = memo[k + 1][j] != -1 ? memo[k + 1][j] : palindromePartition(s, k + 1, j, memo);

            cuts = 1 + left + right;

            res = min(res, cuts);
        }

        return memo[i][j] = res;
    }

    int palPartition(string &s)
    {
        int n = s.size();
        // Initialize with -1
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return palindromePartition(s, 0, n - 1, memo);
    }
};