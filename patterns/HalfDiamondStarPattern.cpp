#include <iostream>
using namespace std;

int main()
{

    int count;
    cout << "Enter a number: ";
    cin >> count;

    for (int i = 1; i <= 2 * count - 1; i++)
    {
        int stars = i;

        if (i > count)
            stars = 2 * count - i;

        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}