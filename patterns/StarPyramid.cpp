#include <iostream>
using namespace std;

int main()
{

    int count;
    cout << "Enter a number: ";
    cin >> count;

    for (int i = 1; i <= count; i++)
    {
        for (int j = 1; j <= count - i - 1; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << "*";
        }
        for (int j = 1; j <= count - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}