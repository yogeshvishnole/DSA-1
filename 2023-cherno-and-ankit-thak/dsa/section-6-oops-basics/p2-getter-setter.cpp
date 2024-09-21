#include <iostream>
using namespace std;

class Student
{

private:
    int age;
    // how to get and set values of private properties of a class
    // Getters and Setters to th rescue

public:
    // to access the property of age outside of the class use the getter function
    int getAge()
    {
        return age;
    }

    // to set the property of age from outside of the class use the setter function
    void setAge(int age)
    {
        // if we can access and modify the private variable using the getters and setter than
        //  what is the use of private, benefit is that we can put validations and restrictions in the setter functions as  -
        if (age < 0)
        {
            cout << "Negative value canr be set";
            return;
        }
        this->age = age;
    }
};

int main()
{

    Student s;
    s.setAge(10);
    cout << "Age of student: " << s.getAge() << endl;

    Student *s2 = new Student;
    s2->setAge(10);
    cout << "Age of student: " << s2->getAge() << endl;
}