#include <iostream>
#include <vector>

long long power(long long a, long long b)
{
    // Base Case: a^0 is always 1
    if (b == 0)
        return 1;

    // Recursive Step: Calculate a^(b/2) once and store it
    long long temp = power(a, b / 2);

    if (b % 2 == 0)
    {
        // If even: (a^b/2)^2
        return temp * temp;
    }
    else
    {
        // If odd: a * (a^b/2)^2
        return a * temp * temp;
    }
}

int main()
{
    std::cout << pow(2, 8);

    return 0;
}