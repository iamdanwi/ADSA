#include <iostream>
#include <vector>

using namespace std;

int trap(vector<int> &height)
{
    int l = 0, r = height.size() - 1, lmax = 0, rmax = 0, water = 0;

    while (l < r)
    {
        if (height[l] < height[r])
        {
            lmax = max(lmax, height[l]);
            water += lmax - height[l];
            l++;
        }
        else
        {
            rmax = max(rmax, height[r]);
            water += rmax - height[r];
            r--;
        }
    }
    return water;
}

int main(int argc, char const *argv[])
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Traped water: " << trap(height) << endl;
    return 0;
}
