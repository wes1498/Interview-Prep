#include <iostream>
#include <vector>
#include <string>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

bool validPosition(vector<string> &board, int row, int col)
{
    int n = board.size();

    for (int x = 1; x <= col; x++)
    {
        if (board[row][col - x] == 'Q')
        {
            return false;
        }
    }
    for (int x = 1; x <= row && x <= col; x++)
    {
        if (board[row - x][col - x] == 'Q')
        {
            return false;
        }
    }
    for (int x = 1; x < n - row && x <= col; x++)
    {
        if (board[row + x][col - x] == 'Q')
        {
            return false;
        }
    }
    return true;
}

void solveBoard(vector<vector<string>> &solutions, vector<string> &board, int col, int n)
{
    if (col == n)
    {
        solutions.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (validPosition(board, row, col))
        {
            board[row][col] = 'Q';
            solveBoard(solutions, board, col + 1, n);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));
    solveBoard(solutions, board, 0, n);
}
