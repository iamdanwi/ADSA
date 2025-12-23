#include <iostream>

int main()
{
    long long n = 5;
    std::cin >> n;
    long long sum = 0, actualSum = n * (n + 1) / 2;

    for (long long int i = 0; i < n - 1; i++)
    {
        long long num;
        std::cin >> num;
        sum += num;
    }

    std::cout << actualSum - sum;

    return 0;
}