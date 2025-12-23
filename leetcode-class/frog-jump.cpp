#include <iostream>
#include <vector>

bool isPossible(std::vector<int> &stones, int index, int lastJump)
{
}

bool canCross(std::vector<int> &stones)
{

    if (stones[1] != 1)
        return false;

    int n = stones.size();
    std::unordered_map<int, int> stoneMap;

    for (int i = 0; i < stones.size(); i++)
    {
        stoneMap[stones[i]] = i;
    }

    std::vector<std::vector<int>> dp;
    dp.assign(n, std::vector<int>(n + 1, -1));

    std::memset(dp, -1, sizeof(dp));
}

int main()
{
    std::vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};

    std::cout << "Frog can " << (canCross(stones) ? "" : "not") << " cross the river.";

    return 0;
}