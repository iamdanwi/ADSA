#include <iostream>
#include <vector>
#include <string>

int LongestRepeatingSubsequence(std::string &s)
{
    int n = s.size();

    std::vector<int> dp(n + 1, 0);

    int prev, curr;

    for (int i = 1; i <= n; i++)
    {
        prev = 0;
        curr = 0;

        for (int j = 1; j <= n; j++)
        {
            prev = curr;
            curr = dp[j];

            if (i != j && s[i - 1] == s[j - 1])
            {
                dp[j] = 1 + prev;
            }
            else
            {
                dp[j] = std::max(dp[j], dp[j - 1]);
            }
        }
    }
    return dp[n];
}

int main()
{
    std::string s = "axxzxy";
    std::cout << "Longest repeating subsequence is: " << LongestRepeatingSubsequence(s);

    return 0;
}