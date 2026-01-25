#include <iostream>
#include <string>
using namespace std;

void reverse_string(string &str, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    swap(str[l], str[r]);
    reverse_string(str, l + 1, r - 1);
}

int main()
{
    string str = "abcd";
    reverse_string(str, 0, str.length() - 1);
    cout << str;
    return 0;
}