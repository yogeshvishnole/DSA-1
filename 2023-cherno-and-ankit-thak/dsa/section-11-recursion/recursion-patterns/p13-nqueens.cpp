
/*
Very very good question.
Concepts used -
1. Backtracking (normal)
2. to optimize each bactracking call, the matrix tricks used are super easy and
 excellent
3. loweDiagonal = right upper to bottom left = row + col = constant
4. upper diagonal = left upper to bottom right = col-row = constant
5. array as a hash, super efficient.

*/

#include <iostream>
#include <vector>
using namespace std;

void solution(int n, int col, int &ans, vector<vector<char>> &chessBoard, vector<int> &rowQueens, vector<int> &lowerDiagonal, vector<int> &upperDiagonal)
{
    if (col == n)
    {
        ans++;
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (rowQueens[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[(n - 1) + (col - row)] == 0)
        {
            chessBoard[row][col] = 'Q';
            rowQueens[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[(n - 1) + (col - row)] = 1;
            solution(n, col + 1, ans, chessBoard, rowQueens, lowerDiagonal, upperDiagonal);
            chessBoard[row][col] = '.';
            rowQueens[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[(n - 1) + (col - row)] = 0;
        }
    }
}

int totalNQueens(int n)
{
    int ans = 0;
    vector<int> rowQueens(n, 0);
    vector<int> lowerDiagonal(2 * n - 1, 0);
    vector<int> upperDiagonal(2 * n - 1, 0);
    vector<vector<char>> chessBoard(n, vector<char>(n, '.'));
    solution(n, 0, ans, chessBoard, rowQueens, lowerDiagonal, upperDiagonal);
    return ans;
}

int main()
{
    cout << totalNQueens(4) << endl;
}