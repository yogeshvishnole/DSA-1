/*
Its game of sudoku, learn the game and solve the problem
*/
#include <iostream>
#include <vector>
using namespace std;

bool sudokuHelper(vector<vector<char>> &board, vector<vector<int>> &rowMap, vector<vector<int>> &colMap, vector<vector<int>> &boxMap)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
            {
                for (char c = '1'; c <= '9'; c++)
                {
                    int el = c - '0' - 1;
                    if (rowMap[el][i] == 0 && colMap[el][j] == 0 && boxMap[el][(i / 3) + ((j / 3) * 3)] == 0)
                    {
                        board[i][j] = c;
                        rowMap[el][i] = 1;
                        colMap[el][j] = 1;
                        boxMap[el][(i / 3) + (j / 3) * 3] = 1;
                        if (sudokuHelper(board, rowMap, colMap, boxMap) == true)
                        {
                            return true;
                        }
                        board[i][j] = '.';
                        rowMap[el][i] = 0;
                        colMap[el][j] = 0;
                        boxMap[el][(i / 3) + (j / 3) * 3] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    int SUDOKU_SIZE = 9;
    vector<vector<int>> rowMap(SUDOKU_SIZE, vector<int>(SUDOKU_SIZE, 0));
    vector<vector<int>> colMap(SUDOKU_SIZE, vector<int>(SUDOKU_SIZE, 0));
    // row*3 + col
    vector<vector<int>> boxMap(SUDOKU_SIZE, vector<int>(SUDOKU_SIZE, 0));

    for (int i = 0; i < SUDOKU_SIZE; i++)
    {
        for (int j = 0; j < SUDOKU_SIZE; j++)
        {
            if (board[i][j] != '.')
            {
                int el = board[i][j] - '0' - 1;
                rowMap[el][i] = 1;
                colMap[el][j] = 1;
                boxMap[el][(i / 3) + (j / 3) * 3] = 1;
            }
        }
    }
    sudokuHelper(board, rowMap, colMap, boxMap);
}

int main() {}