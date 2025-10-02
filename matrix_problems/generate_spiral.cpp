#include <iostream>
#include <vector>

std::vector<std::vector<int>> generateMatrix(int n)
{
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    int num = 1;
    int top = 0, bottom = n - 1, left = 0, right = n - 1;

    while (num <= n * n)
    {
        for (int j = left; j <= right; j++)
            matrix[top][j] = num++;
        top++;

        for (int i = top; i <= bottom; i++)
            matrix[i][right] = num++;
        right--;

        for (int j = right; j >= left; j--)
            matrix[bottom][j] = num++;
        bottom--;

        for (int i = bottom; i >= top; i--)
            matrix[i][left] = num++;
        left++;
    }
    return matrix;
}

int main()
{
    int n = 3;
    auto matrix = generateMatrix(n);
    for (const auto &row : matrix)
    {
        for (int val : row)
            std::cout << val << " ";
        std::cout << "\n";
    }
    return 0;
}
