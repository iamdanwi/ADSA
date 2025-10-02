#include <iostream>
#include <vector>

void setZeroes(std::vector<std::vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    bool firstRow = false, firstCol = false;

    for (int i = 0; i < rows; i++)
    {
        if (matrix[i][0] == 0)
            firstCol = true;
    }
    for (int j = 0; j < cols; j++)
    {
        if (matrix[0][j] == 0)
            firstRow = true;
    }

    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    if (firstCol)
    {
        for (int i = 0; i < rows; i++)
            matrix[i][0] = 0;
    }
    if (firstRow)
    {
        for (int j = 0; j < cols; j++)
            matrix[0][j] = 0;
    }
}

int main()
{
    std::vector<std::vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    setZeroes(matrix);
    for (const auto &row : matrix)
    {
        for (int val : row)
            std::cout << val << " ";
        std::cout << "\n";
    }
    return 0;
}
