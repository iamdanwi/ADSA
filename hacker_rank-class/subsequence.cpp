#include <iostream>
#include <vector>

std::vector<int> longestCommonSubsequence(const std::vector<int> &a, const std::vector<int> &b)
{
    int m = a.size();
    int n = b.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    std::vector<int> lcs;
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            lcs.push_back(a[i - 1]);
            --i;
            --j;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            --i;
        }
        else
        {
            --j;
        }
    }

    std::reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main()
{
    std::vector<int> a = {1, 2, 3, 4, 5};
    std::vector<int> b = {2, 4, 5};

    for (int num : longestCommonSubsequence(a, b))
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}