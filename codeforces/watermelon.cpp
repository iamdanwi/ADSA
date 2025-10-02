#include <iostream>

int main()
{
    int w;
    std::cin >> w;
    std::cout << ((w > 2 && w % 2 == 0) ? "YES" : "NO");
    return 0;
}
