#include <iostream>
#include <string>

using namespace std;

int expand(string &s, int l, int r, int n)
{
    while (l >= 0 && r < n && s[l] == s[r])
    {
        l--;
        r++;
    }
    return r - l - 1;
}

string longest_palindrome(string s)
{
    int n = s.size();
    int start = 0, maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        int odd = expand(s, i, i, n);
        int even = expand(s, i, i + 1, n);

        if (odd > maxLen)
        {
            maxLen = odd;
            start = i - odd / 2;
        }

        if (even > maxLen)
        {
            maxLen = even;
            start = i - even / 2 + 1;
        }
    }
    return s.substr(start, maxLen);
}

int main(int argc, char const *argv[])
{
    string str = "babad";
    cout << longest_palindrome(str) << endl;
    return 0;
}
