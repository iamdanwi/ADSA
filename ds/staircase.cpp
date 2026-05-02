#include <iostream>

using namespace std;

void staircase(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << string(n - i, '.') << string(i, '#') << "\n";
    }
}

int main(int argc, char const *argv[])
{
    staircase(4);
    return 0;
}
