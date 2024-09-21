/*

2D arrays are stored as one dimensional arrays in memory.
There are 2 ways to store 2D arrays in memory in one dimensional arrays.
1. Row major order
2. Column major order

Row major order - In this order, the elements of the first row are stored first, then the elements of the second row and so on.
Column major order - In this order, the elements of the first column are stored first, then the elements of the second column and so on.

In C++ and in most computers, 2D arrays are stored in row major order.

For example, consider the following 2D array:
int arr[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
It will be stored in memory as:
1 2 3 4 5 6

And when we access arr[1][2], it will be calculated as:
base address + (row * number of columns + column) * size of data type

You can see that number of columns in important in 2D arrays because it is used to calculate the position of an element
in memory.Thats why while passing 2D arrays to functions, number of columns is mandatory but number of rows is optional.
And same applies while initializing 2D arrays.



 */