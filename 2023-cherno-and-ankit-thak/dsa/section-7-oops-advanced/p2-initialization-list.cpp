/*

Use of initialization list is to initialize const members and reference members of the class at the time of memory allocation.

Note const variables and reference variables cannot be reassigned and their values have to be provided at the time of their
creation only otherwise they serve no purpose in the program, thats why if we do not provide value at the time of their creation compiler will throw error
 */

#include <iostream>
using namespace std;

class Student
{
    int age;
    int const rollNumber;
    int &x; // x will store the reference od age member

    Student(int age, int rollNumber) : rollNumber(rollNumber), age(age), x(this->age)
    {
        // now we cannot write as this-rollNumer = rollNumber because rollNumber is a constant variable and
        // constant variabled cant be declared after their initializatipn and class members get their memory as soon
        // as constructor got executed, thats why we have to use the initialization list to give the value to
        // constant variabled and reference class members to assign them value at the time of their creation
        // initialization list can also be used for normal varables as used above for age
    }
};

int main() {}