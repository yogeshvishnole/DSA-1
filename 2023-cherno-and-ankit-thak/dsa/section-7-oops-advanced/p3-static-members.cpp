#include <iostream>
using namespace std;

class Student
{
    int age;
    int rollNumber;

public:
    static int totalStudents;
    // static members are shared by all the objects of the class, they are not copied to each object

    Student()
    {
        totalStudents++;
    }

    // static methods can only access static members
    // static methods can be called using class name, no need to create object
    // static methods can only call other static methods
    // statuc methods does not have this pointer
    static int getTotalStudents()
    {
        return totalStudents;
    };
};
int Student::totalStudents = 20; // we can initialize static members ONLY outside the class, :: is scope resolution operator

int main()
{
    Student s1;
    Student s2;
    cout << Student::totalStudents << endl;
    cout << s1.totalStudents << endl; // comipler will allow this but it is not a good practice to access static members using objects
    return 0;
}