#include <iostream>
#include <vector>

int diagonalDifference(std::vector<std::vector<int>> &mat)
{
    int n = mat.size(), leftSum = 0, rightSum = 0;

    for (int i = 0; i <= n - 1; i++)
    {
        leftSum += mat[i][i];
        rightSum += mat[i][n - i - 1];
    }

    return abs(leftSum - rightSum);
}

int main(int argc, char const *argv[])
{
    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {9, 8, 9}};

    // std::cout << "Absolute diffrence between left and right diagonal is: " << diagonalDifference(mat) << std::endl;
    std::cout << diagonalDifference(mat);

    return 0;
}
