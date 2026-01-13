#include <iostream>

int main()
{
    int count;
    std::cin >> count;
    for (size_t i = 0; i < count; i += count / 2)
    {
        std::cout << "Hello, World!" << std::endl;
    }

    return 0;
}