// including a header file

#include <iostream>
using namespace std;

    /*
    What is function ?

    Function is a entity which takes one or more input and returns an output.

    #include is a preprocessor directive.

    */
    // here int is return type of function
    int
    main()
{

    // Function body  goes here

    // we can print on standard output via cout as
    // cout << "Hello World";
    // cout << endl;
    // cout << "Line 2\n";

    // What is variable ?
    // name of a memory location

    // int -> 4 byte

    int num = 50;
    cout << sizeof(num) << endl;
    char ch = 19;
    cout << ch << endl;

    // String is inside double quotes
}

/*
Other things that we learn in this  lecture

1. Actual representation of data in memory in form of bits.
2. like char is of 1 byte = 8 bit then it will store in memory as -
'a' == ascii = 97 ->
 128    64    32   16   8    4    2     1
|  0  |  1  | 1  |  0 | 0  | 0  | 0   | 1  | <--- This is how a char store in memory

Similarly int = 4 byte = 32 bit stored in memory in 32 blocks of bits

byte is the smallest addressable block of memory.

Ranges of datatypes

Unsigned let n = no. of bits then range will be 0 to (2 raise to the power n) - 1
In case of signed 1 bit is reserved for sign -> then range becomes ( - 2 raise to the power n-1) to (2 rause to the power(n-1) -1)

For example -
int = 4 byte then its range become - 4 bytes = 32 bit then its signed range become -
n = 32
- 2 raise to the power 31 to 2 raise to the power 31 - 1

How to represent negative numbers -

Three steps for getting representation of negative number

Then operators -
1. Arithmetic + . - , * /, %
2. Logical = &&, || , !
3. bitwise & , | , ^, !
4. assignment operator - =, += -= *= /=-
5. Relational operator - < , > ,<= , >=

What is number system ?
Ans ->
The number system is a way to represent or express numbers. You have heard of various types of number systems such as the whole numbers and the real numbers. But in the context of computers, we define other types of number systems. They are:

The decimal number system
The binary number system
The octal number system and
The hexadecimal number system

https://www.toppr.com/guides/computer-aptitude-and-knowledge/basics-of-computers/number-systems/




*/
