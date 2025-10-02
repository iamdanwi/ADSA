#include <iostream>

int main()
{
    long long n, k;
    std::cin >> n >> k;

    long long mid = (n + 1) / 2;
    if (k <= mid)
    {
        std::cout << 2 * k - 1;
    }
    else
    {
        std::cout << 2 * (k - mid);
    }
    return 0;
}
