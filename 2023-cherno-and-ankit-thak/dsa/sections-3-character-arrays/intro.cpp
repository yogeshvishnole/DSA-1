#include<iostream>
using namespace std;

/* 
Character arrays are used to store strings in C++
They are arrays of characters
They are null terminated, which means they have a null character at the end
The null character is '\0'
Ascii value of null character is 0
The null character is used to determine the end of the string
The null character is automatically added to the end of the string when we use double quotes
We can also add the null character manually
We can access the individual characters of the string using the index
We can also modify the individual characters of the string using the index
We can also use the cin object to input strings
The cin object stops reading the string when it encounters a whitespace character
We can use the getline function to read the entire line
The getline function reads the entire line until it encounters a newline character 
*/

/* 
Difference between normal arrays and character arrays are as follows
Normal arrays are used to store integers, floats, etc
Character arrays are used to store strings
Strings are sequences of characters
Strings are enclosed in double quotes
Strings are stored as character arrays in C++
Strings are stored as null terminated character arrays
 */

/* 
Also note that cout and cin operators are overloaded to work with character arrays as follows -
cin takes the input as string and put each character at each index of the character array and as it gets
a whitespace character, it stops reading the string and put a null character at the last index of the
character array and 
cout prints the string until it encounters a null character
 */



int main() {
    char name[20];
    cout << "Enter your name: ";
    // lets say I enter abc then it will be stored as a b c \0
    // c is at index 2 and \0 is at index 3 if I replace value of index of c to null 
    // characeter then cout will only print a b
    cin >> name;
    name[2] = '\0';
   
    cout << "Your name is " << name << endl;
    // if character array is not null terminated at any index then cout will print the entire array
    return 0;
}