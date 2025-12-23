#include <iostream>
#include <vector>
#include <string>

int findlcs(std::string &str1, std::string &str2)
{
    int m = str1.size();
    int n = str2.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int minOperations(std::string &s1, std::string &s2)
{
    int lcslength = findlcs(s1, s2);
    int insertion = s2.length() - lcslength;
    int deletion = s1.length() - lcslength;
    return insertion + deletion;
}

int main()
{
    std::string str1 = "geeksforgeeks", str2 = "geeks";
    std::cout << "Minimum poeration is: " << minOperations(str1, str2);
    return 0;
}