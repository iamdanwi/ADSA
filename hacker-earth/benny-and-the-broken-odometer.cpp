#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

long long memo[15][2][2];
string s;

long long solveDP(int idx, bool isLess, bool hasThree)
{
    if (idx == s.size())
    {
        return hasThree ? 1 : 0;
    }

    if (memo[idx][isLess][hasThree] != -1)
    {
        return memo[idx][isLess][hasThree];
    }
    long long limit = isLess ? 9 : (s[idx] - '0');
    long long total = 0;
    for (int digit = 0; digit <= limit; digit++)
    {
        total += solveDP(idx + 1, isLess || (digit < limit), hasThree || (digit == 3));
    }
    return memo[idx][isLess][hasThree] = total;
}

void solve()
{
    long long n;
    if (!(cin >> n))
        return;

    s = to_string(n);
    memset(memo, -1, sizeof(memo));

    long long numbersWithThree = solveDP(0, false, false);
    cout << n - numbersWithThree << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}