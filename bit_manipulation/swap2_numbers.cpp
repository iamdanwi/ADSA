#include <iostream>

void swapNubers(int x, int y)
{
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
    std::cout << "Value of x is: " << x << std::endl;
    std::cout << "Value of y is: " << y << std::endl;
}

int main(int argc, char const *argv[])
{
    int x = 5, y = 6;
    swapNubers(x, y);
    return 0;
}
