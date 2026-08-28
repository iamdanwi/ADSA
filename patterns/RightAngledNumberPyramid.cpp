#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int count;
    cout << "Enter the number: " << endl;
    cin >> count;

    for (int i = 1; i <= count; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
