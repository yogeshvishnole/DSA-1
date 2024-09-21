#include <iostream>
#include "product.cpp" // double quotes are used for user defined header files
using namespace std;

// Access modifiers in classes
/*
There are three access modifiers in classes:
1. Public: The members of the class declared as public are accessible from anywhere in the program.
2. Private: The members of the class declared as private are accessible only from within the class.
3. Protected: The members of the class declared as protected are accessible from within the class and from the classes derived from that class.
 */

class Student
{
public:
    string name;
    int age;
    int rollNumber;

private:
    int password;
};

int main()
{
    // Creating objects statically (in stack memory restrictive and less in size but fast)
    Student s1;
    Student s2;
    Student s3, s4, s5;

    // Creating objects dynamically (in heap memory)
    Student *s6 = new Student;

    // Accessing the members of the object and assigning values for static objects
    s1.name = "John";
    s1.age = 24;
    s1.rollNumber = 101;
    cout << s1.name << " " << s1.age << " " << s1.rollNumber << endl;

    // Accessing the members of the object and assigning values for dynamic objects
    s6->name = "Doe";     // (*s6).name = "Doe"; Arrow syntax is shortcut for (*s6) or that is alias syntax for (*s6)
    s6->age = 25;         // (*s6).age = 25;
    s6->rollNumber = 102; // (*s6).rollNumber = 102;
    cout << s6->name << " " << s6->age << " " << s6->rollNumber << endl;

    // using the imported class Product
    Product p1;
    p1.id = 101;
    cout << p1.id << endl;
}