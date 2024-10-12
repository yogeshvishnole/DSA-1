/*

Limitations of the cin function in case of character arrays -
1. It can not take inputs like 'Hello World' as its delimiter is space or tab or newline \n character
2. It allows to input beyond the size of our character array.

NOTE - for character array like char input[n] the number of characters it can accomodate is n-1 as 1 place is
reserved for '\0' null character, and for integer arra like int input[n] number of elements it can accomodate
= n.

cin.getline function to rescue
1. signature cin.getline(inputCharArray,sizeOfArray,optional delimiter)
2. default delimiter for cin.getline is \n (newline character) and we can replace it with any character by
passing that character in its third arg as cin.getline(a,100,'o') now o become the delimiter
3. cin.getline will only store the length-1 characters in the input array.

 */

#include <iostream>
using namespace std;

int main()
{

    // char input[4];
    // cout << "Enter something:";
    // cin.getline(input, 4);
    // // cin.getline(input, 10); -> This is allowed but dont do this as it accesses the memory
    // // outside of your program and create ubdefined situation
    // cout << "Output: " << input << endl;

    // Lets change the delimieter to o

    char input2[10];
    cout << "Enter something 2: ";
    cin.getline(input2, 10, 'o');

    cout << "Output 2: " << input2 << endl;
    ;
}
