#include <iostream>
#include <string>

using namespace std;

string numToBinary(int x)
{
    string res = "";

    while (x > 0)
    {
        if (x % 2 == 1)
        {
            res += '1';
        }
        else
        {
            res += '0';
        }
        x = x / 2;
    }
    reverse(res.begin(), res.end());

    return res;
}

bool checkSetBit(string bits, int pos)
{
    cout << "ith bit is " << bits[pos] << endl;
    return bits[pos] == '1';
}

int main(int argc, char const *argv[])
{
    int n = 13, i = 1;
    cout << "The binary of " << n << " is " << numToBinary(n) << endl;
    cout << "The " << i << "th bit is " << (checkSetBit(numToBinary(n), i) ? "set" : "not set\n");
    return 0;
}
