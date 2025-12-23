#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long int

bool check(ll mid, ll n, ll t, std::vector<ll> &nums)
{
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (mid / nums[i]);
        if (sum >= t)
            return true;
    }
    return false;
}

ll calculateTime(ll n, ll t, std::vector<ll> &nums)
{
    ll res = 0, low = 1, high = (*std::max_element(nums.begin(), nums.end())) * t;

    while (low <= high)
    {
        ll mid = low + (high - low) / 2;

        if (check(mid, n, t, nums))
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}

int main()
{
    ll n, t;
    std::cin >> n >> t;
    std::vector<ll> nums(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }

    std::cout << calculateTime(n, t, nums);

    return 0;
}