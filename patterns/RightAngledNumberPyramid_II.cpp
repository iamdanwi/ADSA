#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int count;
    cout << "Enter the number: ";
    cin >> count;

    for (int i = 1; i <= count; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
    return 0;
}
