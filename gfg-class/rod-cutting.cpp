#include <iostream>
#include <vector>

int cutRoad(std::vector<int> &price)
{
    int n = price.size();
    std::vector<int> dp(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int currentCutLength = i + 1;
        for (int j = currentCutLength; j <= n; j++)
        {
            dp[j] = std::max(dp[j], price[i] + dp[j - currentCutLength]);
        }
    }
    return dp[n];
}

int main()
{
    std::vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};

    std::cout << cutRoad(price);

    return 0;
}