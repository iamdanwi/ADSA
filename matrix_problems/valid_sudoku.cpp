#include <iostream>
#include <vector>
#include <unordered_set>

bool isValidSudoku(std::vector<std::vector<char>> &board)
{
    std::vector<std::unordered_set<char>> rows(9);
    std::vector<std::unordered_set<char>> cols(9);
    std::vector<std::unordered_set<char>> boxes(9);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
                continue;

            int box_idx = (i / 3) * 3 + j / 3;
            char curr = board[i][j];

            if (rows[i].count(curr) || cols[j].count(curr) || boxes[box_idx].count(curr))
                return false;

            rows[i].insert(curr);
            cols[j].insert(curr);
            boxes[box_idx].insert(curr);
        }
    }
    return true;
}

int main()
{
    std::vector<std::vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    std::cout << (isValidSudoku(board) ? "Valid" : "Invalid");
    return 0;
}
