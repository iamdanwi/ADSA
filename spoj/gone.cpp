#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

long long dp[10][82][2];
vector<int> digits;
bool prime[73];

void sieve()
{
    fill(prime, prime + 200, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < 200; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j < 200; j += i)
                prime[j] = false;
        }
    }
}

long long solve_dp(int idx, int sum, bool tight)
{
    if (idx < 0)
        return prime[sum];
    if (dp[idx][sum][tight] != -1)
        return dp[idx][sum][tight];

    long long ans = 0;
    int limit = tight ? digits[idx] : 9;

    for (int i = 0; i <= limit; i++)
    {
        ans += solve_dp(idx - 1, sum + i, tight && (i == limit));
    }

    return dp[idx][sum][tight] = ans;
}

long long calc(long long n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 0;

    digits.clear();
    while (n)
    {
        digits.push_back(n % 10);
        n /= 10;
    }

    memset(dp, -1, sizeof(dp));
    return solve_dp(digits.size() - 1, 0, true);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            long long a, b;
            cin >> a >> b;
            cout << calc(b) - calc(a - 1) << "\n";
        }
    }
    return 0;
}