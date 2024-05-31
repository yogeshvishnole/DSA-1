#include <iostream>

// input array a -> 1,2,3,4
// ouput array a --> 4,3,2,1
// same array should be reversed.
int main()
{

    std::cout << "Enter length of input array: " << std::endl;
    int n;
    std::cin >> n;

    int array[n];

    std::cout << "Enter array elements: " << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cin >> array[i];
    }

    std::cout << "Array elements are: " << std::endl;

    for (int i = 0; i < n; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    /**
     *
     * Algorithm
     * Given array -> 1,2,3,4 or 1,2,3,4,5
     * we will start from i =0 and iterate till k;
     * where k = n/2 when n is even or n-1/2 when n is odd
     * in each iteration we will swap array[i] and array[n-(i+1)]
     *
     * */

    int k = n % 2 == 0 ? n / 2 : (n - 1) / 2;

    for (int i = 0; i < k; i++)
    {
        std::swap(array[i], array[n - (i + 1)]);
    }

    std::cout << "Printing the reversed array: " << std::endl;

    for (int i = 0; i < n; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}