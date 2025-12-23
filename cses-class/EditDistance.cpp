#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int dp(const std::string &str1, const std::string &str2, int i, int j, std::vector<std::vector<int>> &tempStore)
{
    if (i == 0)
        return j;
    if (j == 0)
        return i;
    if (tempStore[i][j] != -1)
        return tempStore[i][j];

    if (str1[i - 1] == str2[j - 1])
    {
        tempStore[i][j] = dp(str1, str2, i - 1, j - 1, tempStore);
    }
    else
    {
        tempStore[i][j] = 1 + std::min({dp(str1, str2, i - 1, j, tempStore), dp(str1, str2, i, j - 1, tempStore), dp(str1, str2, i - 1, j - 1, tempStore)});
    }

    return tempStore[i][j];
}

int minDistance(std::string str1, std::string str2)
{
    int m = str1.size();
    int n = str2.size();
    std::vector<std::vector<int>> tempStore(m + 1, std::vector<int>(n + 1, -1));
    return dp(str1, str2, m, n, tempStore);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string str1, str2;
    std::cin >> str1;
    std::cin >> str2;

    std::cout << minDistance(str1, str2);

    return 0;
}