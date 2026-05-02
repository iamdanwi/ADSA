#include <iostream>
#include <string>

using namespace std;

string decToBinary(int n)
{
    string res = "";
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            res += "1";
        }
        else
        {
            res += "0";
        }
        n = n / 2;
    }
    reverse(res.begin(), res.end());
    return res;
}
int hammingWeight(int n)
{
    string bits = decToBinary(n);
    int count = 0;
    for (int i = 0; i < bits.length(); i++)
    {
        if (bits[i] == '1')
        {
            count++;
        }
    }
    return count;
}

int hammingWeight(int n)
{
    int count = 0;
    while (n)
    {
        n &= (n - 1);
        count++;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    int n = 13;
    cout << "The number of set bit is: " << hammingWeight(n) << endl;
    return 0;
}
