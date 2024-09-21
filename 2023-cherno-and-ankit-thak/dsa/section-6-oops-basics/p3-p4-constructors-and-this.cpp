/*

Constructors are special member functions of a class that are automatically called when an object of the class is created.
Constructors have the same name as the class and do not have a return type and default constructor does not have any parameter.
Constructors can be used to initialize the object's data members.
Constructors can be overloaded, which means a class can have multiple constructors with different parameters.
Constructors is called only once when the object is created.

With the help of constructor we can add the contraint that the object should be created with some values only,
if we do not want to create an object without values or with garbage values then we can use the constructor to enforce this constraint.
by removing the default constructor we can enforce this constraint.

 */

#include <iostream>
using namespace std;

class Student
{
public:
    string name;
    int age;
    int rollNumber;

    // Note as soon as we define a constructor, the default constructor is not available, so if we only define the parameterized constructor
    // then we cannot create an object without passing the parameters, so we have to define the default constructor explicitly

    // default constructor
    Student()
    {
        cout << "Value of this: " << this << endl;
        cout << "Default constructor called" << endl;
    }

    // parameterized constructor
    Student(string name, int age, int rollNumber)
    {

        // if parameter name and class property name are same then we have to use
        // this keyword to differentiate between them, other wise the result will not be as expected
        // this keyword is a pointer to the current object of the class
        // this keyword holds the address of the current object
        // every function of the class has access to this pointer/keyword
        // we can prove that this holds the address of the current object by printing the value of this and the address of the object
        this->name = name;
        this->age = age;
        this->rollNumber = rollNumber;
        cout << "Parameterized constructor called" << endl;
    }
};

int main()
{
    Student s1; // default constructor called == s1.Student();
    cout << "Address of s1: " << &s1 << endl;
    Student s2("John", 24, 101); // parameterized constructor called

    cout << "Name: " << s2.name << " Age: " << s2.age << " Roll Number: " << s2.rollNumber << endl;
    return 0;
}
