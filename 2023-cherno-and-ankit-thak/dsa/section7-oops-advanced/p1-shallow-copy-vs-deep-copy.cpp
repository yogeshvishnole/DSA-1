/*
Copy only the references od the objects, not the actual objects, it is called shallow copy.
Deep copy is the process of creating a new object and copying the values of the original object to the new object.

NOTE - Inbuilt copy constructor always created shallow copy, but we want deep copy so we should create our own copy constructor,
and while creating copy constructor always take the original object as pass by referemce otherwise our copy constructor will
stuck into infinit loop as without pass by reference the object from main will get copied into our paraeter and hence
for creating copy contructior we will need copy consturctor and we will ctuck in infinite loop
 */

#include <iostream>
using namespace std;

class Student
{
private:
    int age;

public:
    char *name;
    Student(Student const &s2)
    {
        this->age = s2.age;
        // this->name = name; It is shallow copy
        // Below is deep copy
        this->name = new char[strlen(s2.name) + 1];
        strcpy(this->name, s2.name);
    }

    Student(int age, char name[])
    {
        this->age = age;
        // this->name = name; It is shallow copy
        // Below is deep copy
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void display()
    {
        cout << "age: " << this->age << " " << "name: " << this->name << endl;
    }
};

int main()
{

    /*
    // Deep copy demo
    char name[] = "abcd";
     Student s1(10, name);
     s1.display();
     name[3] = 'e';
     Student s2(20, name);
     s2.display();
     s1.display(); */

    // custom copy constructor demo
    char name[] = "abcd";
    Student s1(10, name);
    s1.display();
    Student s2(s1);
    s1.name[3] = 'e';
    s1.display();
    s2.display();
}