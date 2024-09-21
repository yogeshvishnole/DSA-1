/*

As soon as we create our class we get the following features by default -
1. default constructor
2. copy constructor
3. copy assignment operator
4. destructor

Copy constructor is a special constructor in C++ that initializes an object using another object of the same class.
It is called when a new object is created as a copy of an existing object.
The copy constructor has a single parameter which is a reference to an object of the same class.

Copy assignment operator is used to copy the values from one object to another already existing object while copy constructor is used to create a new object.

Destructor is a special member function that is called when an object is destroyed or when object scope end.
It has the same name as the class but is preceded by a tilde (~) and
It  does not take any parameters or
It does not have  any return value.
THere can be only one destructor in a class.
If we do not define a destructor, the compiler will automatically create a default destructor.
If we define a destructor, the compiler will not create a default destructor.

 */

#include <iostream>
using namespace std;

class Student
{
public:
    int age;
    int rollNumber;

    Student(int age, int rollNumber)
    {
        this->age = age;
        this->rollNumber = rollNumber;
    }

    ~Student()
    {
        cout << "Destructor called" << endl;
    }
};

int main()
{
    /*   // Copy Constructor
      Student s1(10, 100); // parameterized constructor called
      cout << "Age: " << s1.age << " Roll Number: " << s1.rollNumber << endl;

      // Copy constructor is called here
      Student s2(s1); // s2 is initialized with s1

      cout << "Age: " << s2.age << " Roll Number: " << s2.rollNumber << endl;

      // Exmmpple with dynamic memory allocation
      Student *s3 = new Student(20, 200);
      cout << "Age: " << s3->age << " Roll Number: " << s3->rollNumber << endl;
      Student *s4 = new Student(*s3); // Copy constructor is called here
      cout << "Age: " << s4->age << " Roll Number: " << s4->rollNumber << endl;
      Student s5(*s3);
      cout << "Age: " << s5.age << " Roll Number: " << s5.rollNumber << endl;
      Student s6(s1);
      cout << "Age: " << s6.age << " Roll Number: " << s6.rollNumber << endl; */

    // Copy Assignment Operator

    Student s1(10, 100); // parameterized constructor called
    cout << "Age: " << s1.age << " Roll Number: " << s1.rollNumber << endl;
    Student s2(20, 100);
    cout << "Age: " << s2.age << " Roll Number: " << s2.rollNumber << endl;

    Student *s3 = new Student(20, 200);
    s2 = s1; // Copy assignment operator is called here
    cout << "Age: " << s2.age << " Roll Number: " << s2.rollNumber << endl;

    s1 = *s3; // Copy assignment operator is called here
    cout << "Age: " << s1.age << " Roll Number: " << s1.rollNumber << endl;

    Student s4 = s1; // Copy constructor is called here because compiler will optimize this line of code and interpret it as Student s4(s1)

    // Note destructor will be called automatically when the object goes out of scope and it is only for statically allocated objects
    // for dynamically allocated objects we have to deallocate memory manually and that will trigger the destructor
    delete s3; // Destructor called

    return 0;
}