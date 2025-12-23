#include <iostream>
#include <algorithm>

int mySqrt(int n)
{
    int l = 1, h = n;
    long ans = 0;

    while (l <= h)
    {
        long mid = l + (h - l) / 2;
        if ((mid * mid) <= n)
        {
            ans = mid;
            l = mid + 1;
        }
        else if ((mid * mid) > n)
        {
            h = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << "The number is: " << mySqrt(n) << "\n";
    return 0;
}