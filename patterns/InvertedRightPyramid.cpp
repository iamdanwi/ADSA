#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int count;
    cout << "Enter the number: ";
    cin >> count;

    for (int i = count; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}
