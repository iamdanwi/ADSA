#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string binaryToDecimal(int n)
{
    string res = "";

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            res += '1';
        }
        else
        {
            res += '0';
        }
        n = n / 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(int argc, char const *argv[])
{
    int n = 7;
    cout << "The binary of " << n << " is " << binaryToDecimal(n) << endl;
    return 0;
}
