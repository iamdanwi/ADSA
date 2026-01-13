#include <iostream>
#include <vector>

int distribute(int n, int m, int k, std::vector<int> &applicants, std::vector<int> &apartments)
{
    int count = 0, i = 0;
    while (i <= n)
    {
        /* code */
    }

    return count;
}

int main()
{
    int n = 4, m = 3, k = 5;

    std::vector<int> applicants = {60, 45, 80, 60};
    std::vector<int> apartments = {30, 60, 75};

    std::cout << distribute(n, m, k, applicants, apartments);

    return 0;
}