#include <iostream>

int m, n;

// bool canReachEnd(int row, int column, int currentHealth, std::vector<std::vector<int>> &dungeon)
// {

//     // 1. Check Bounds: If we go outside the grid, this path is invalid
//     if (row >= m || column >= n)
//         return false;

//     currentHealth += dungeon[row][column];

//     if (currentHealth <= 0)
//         return false;

//     if (row == m - 1 || column == n - 1)
//         return true;

//     bool goRight = canReachEnd(row, column + 1, currentHealth, dungeon);
//     bool goDown = canReachEnd(row + 1, column, currentHealth, dungeon);

//     return goRight || goDown;
// }

// int calculateMinimumHp(std::vector<std::vector<int>> &dungeon)
// {
//     m = dungeon.size();
//     n = dungeon[0].size();

//     int low = 1, high = 1e9;

//     int ans = high;

//     while (low <= high)
//     {
//         int mid = low + (high - low) / 2;

//         if (canReachEnd(0, 0, mid, dungeon))
//         {
//             ans = mid;
//             high = mid - 1;
//         }
//         else
//         {
//             low = mid + 1;
//         }
//     }
//     return ans;
// }

int calculateMinimumHP(std::vector<std::vector<int>> &dungeon)
{
    int m = dungeon.size();
    int n = dungeon[0].size();

    // Use N+1 size initialized to INT_MAX (represents walls)
    std::vector<int> dp(n + 1, INT_MAX);

    // This '1' is the minimum health needed AT the princess's location
    // to survive "exiting" the dungeon.
    dp[n - 1] = 1;

    // Iterate backwards from the last row to the first
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {

            // min(Down, Right)
            // dp[j] is the value from the previous iteration (Down)
            // dp[j+1] is the value we just updated (Right)
            int minNeed = std::min(dp[j], dp[j + 1]);

            int currentNeed = minNeed - dungeon[i][j];

            // Ensure we have at least 1 HP
            dp[j] = std::max(1, currentNeed);
        }
    }

    return dp[0];
}
int main()
{
    std::vector<std::vector<int>> dungeon = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    std::cout << calculateMinimumHP(dungeon);

    return 0;
}