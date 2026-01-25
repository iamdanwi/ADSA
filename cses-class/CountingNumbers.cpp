#include <bits/stdc++.h>
using namespace std;

long long memo[20][2][11][2];
bool vis[20][2][11][2];

long long count_numbers(string &s, int idx, bool tight, int prev, bool lead_zero)
{
    if (idx == (int)s.size())
        return 1;

    long long &res = memo[idx][tight][prev][lead_zero];
    if (vis[idx][tight][prev][lead_zero])
        return res;
    vis[idx][tight][prev][lead_zero] = true;

    res = 0;
    int ub = tight ? s[idx] - '0' : 9;

    for (int digit = 0; digit <= ub; digit++)
    {
        if (!lead_zero && digit == prev)
            continue;

        bool new_lead = lead_zero && (digit == 0);
        int new_prev = new_lead ? 10 : digit;

        res += count_numbers(
            s,
            idx + 1,
            tight && (digit == ub),
            new_prev,
            new_lead);
    }
    return res;
}

long long solve(long long x)
{
    if (x < 0)
        return 0;
    string s = to_string(x);
    memset(vis, false, sizeof(vis));
    return count_numbers(s, 0, true, 10, true);
}

int main()
{
    long long n, m;
    cin >> n >> m;
    cout << solve(m) - solve(n - 1);
    return 0;
}
