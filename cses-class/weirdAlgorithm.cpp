#include <iostream>

void calc(long long n)
{
    while (true)
    {
        std::cout << n << " ";
        if (n == 1)
            break;

        if (n % 2 == 0)
            n /= 2;
        else
            n = n * 3 + 1;
    }
}

int main()
{
    int n;
    std::cin >> n;
    calc(n);
    return 0;
}