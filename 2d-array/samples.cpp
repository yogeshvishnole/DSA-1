#include <iostream>
#include <vector>
using namespace std;

// function to print 2d array
void print2dArray(int arr[3][3], int row, int col)
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void print2dArrayColumnWise(int arr[4][3], int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
}

bool searchIn2dArray(int arr[3][3], int row, int col, int target)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
}

void rowWiseSum(int arr[3][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
        cout << "Sum of row " << i << " is " << sum << endl;
    }
}

void columnWiseSum(int arr[3][3], int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        int sum = 0;
        for (int j = 0; j < row; j++)
        {
            sum += arr[j][i];
        }
        cout << "Sum of column " << i << " is " << sum << endl;
    }
}

void transpose(int arr[3][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i < j)
            {
                swap(arr[i][j], arr[j][i]);
            }
        }
    }
}

int main()
{

    // create an 2d array
    // int carr[3][4];

    // declaration and initialization of 2d array

    // int arr[4][3] = {
    //     {10, 20, 30},
    //     {1, 2, 3},
    //     {4, 6, 8},
    //     {5, 7, 9}};

    // actually our machine stores 2d array in the form of single array as
    // {10,20,30,1,2,3,4,6,8,5,7,9} and the formula used for calculating index in that single array by our compilr is = c*i + j where c = no. of column It can be other way around as -
    //    {10,1,4,5,20,2,6,7,30,3,8,9}  here formula will be r*j + i
    // but mostly in modern machined the former/first approach is used thats why learn the formula = c*i +j

    // this is the reason why column count is required while declaring and initializing the 2d array

    // int adrrr[3][4]; // -> It is fine
    // int fore[3][4];  // it wil not work

    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // print2dArray(arr, 4, 3);
    // print2dArrayColumnWise(arr, 4, 3);

    // input in 2d array

    // int arrInput[3][3];

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cout << "Enter row index " << i << " column index " << j << " ";
    //         cin >> arrInput[i][j];
    //     }
    // }

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cout << arrInput[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // int n;
    // cin>>

    // int target;
    // cout << "Enter target to search : ";
    // cin >> target;

    // cout << searchIn2dArray(arrInput, 3, 3, target) << endl;
    // transpose(arrInput, 3, 3);
    // rowWiseSum(arrInput, 3, 3);
    // columnWiseSum(arrInput, 3, 3);
    // print2dArray(arrInput, 3, 3);

    // 2d array using vector
    // vector<vector<int>> arr(5, vector<int>(10, -1));
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     for (int j = 0; j < arr[i].size(); j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // Jagged Array
    vector<vector<int>> jaggedArray;

    vector<int> vec1(10, 0);
    vector<int> vec2(6, 0);
    vector<int> vec3(4, -1);
    vector<int> vec4(7, 9);

    jaggedArray.push_back(vec1);
    jaggedArray.push_back(vec2);
    jaggedArray.push_back(vec3);
    jaggedArray.push_back(vec4);

    for (int i = 0; i < jaggedArray.size(); i++)
    {
        for (int j = 0; j < jaggedArray[i].size(); j++)
        {
            cout << jaggedArray[i][j] << " ";
        }
        cout << endl;
    }
}