#include <iostream>
#include <string>

using namespace std;

int binaryToDecimal(string binaryNum)
{
    int len = binaryNum.length(), p2 = 1, num = 0;

    for (int i = len - 1; i >= 0; i--)
    {
        if (binaryNum[i] == '1')
        {
            num = num + p2;
        }
        p2 = p2 * 2;
    }

    return num;
}

int main(int argc, char const *argv[])
{
    string binaryNum = "111";
    cout << "The decimal conversion of binary " << binaryNum << " is " << binaryToDecimal(binaryNum) << endl;
    return 0;
}
