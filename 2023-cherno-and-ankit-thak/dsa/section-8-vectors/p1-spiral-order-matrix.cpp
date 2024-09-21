#include <iostream>
#include <vector>
using namespace std;

vector<int> printMatrixSpirally(vector<vector<int>> const &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int sr = 0;
    int sc = 0;
    int er = m - 1;
    int ec = n - 1;

    vector<int> resultVector;
    int count = 0;

    while ((sr <= er && sc <= ec) && (count <= m * n))
    {
        // Print the start row
        for (int j = sc; j <= ec; j++)
        {
            resultVector.push_back(matrix[sr][j]);
            count++;
        }
        sr++;
        if (count == m * n)
        {
            return resultVector;
        }
        // print the end column
        for (int i = sr; i <= er; i++)
        {
            resultVector.push_back(matrix[i][ec]);
            count++;
        }
        ec--;
        if (count == m * n)
        {
            return resultVector;
        }
        // print the end row
        for (int j = ec; j >= sc; j--)
        {
            resultVector.push_back(matrix[er][j]);
            count++;
        }
        er--;
        if (count == m * n)
        {
            return resultVector;
        }
        // print the start column
        for (int i = er; i >= sr; i--)
        {
            resultVector.push_back(matrix[i][sc]);
            count++;
        }
        sc++;
        if (count == m * n)
        {
            return resultVector;
        }
    }
    for (int i = 0; i < resultVector.size(); i++)
    {
        cout << resultVector[i] << " ";
    }
    cout << endl;
    return resultVector;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};
    vector<int> resultVector = printMatrixSpirally(matrix);
    for (int i = 0; i < resultVector.size(); i++)
    {
        cout << resultVector[i] << " ";
    }
    cout << endl;
}
