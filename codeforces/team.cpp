#include <iostream>

int main()
{
    int n, count = 0;
    std::cin >> n;

    while (n--)
    {
        int p, v, t;
        std::cin >> p >> v >> t;
        if (p + v + t >= 2)
            count++;
    }

    std::cout << count;
    return 0;
}
