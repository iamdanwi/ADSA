#include <iostream>
#include <vector>

int maximumNumberOfPages(std::vector<int> &price, std::vector<int> &pages, int numberOfBooks, int money)
{

    if (numberOfBooks == 0 || money == 0)
        return 0;

    std::vector<int> dp(money + 1, 0);

    for (int i = 0; i < numberOfBooks; i++)
    {
        for (int j = money; j >= price[i]; j--)
        {
            dp[j] = std::max(dp[j], pages[i] + dp[j - price[i]]);
        }
    }
    return dp[money];
}

int main()
{
    // int numberOfBooks = 4, money = 10;
    int numberOfBooks, money;
    std::cin >> numberOfBooks >> money;
    // std::vector<int> price = {4, 8, 5, 3};
    std::vector<int> price(numberOfBooks);
    for (int i = 0; i < numberOfBooks; i++)
    {
        std::cin >> price[i];
    }
    // std::vector<int> pages = {5, 12, 8, 1};
    std::vector<int> pages(numberOfBooks);
    for (int i = 0; i < numberOfBooks; i++)
    {
        std::cin >> pages[i];
    }

    std::cout << maximumNumberOfPages(price, pages, numberOfBooks, money);

    return 0;
}