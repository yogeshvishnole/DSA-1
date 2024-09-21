#include <iostream>
using namespace std;

int gcd(int num1, int num2)
{
    if (num2 == 0)
        return num1;
    return gcd(num2, num1 % num2);
}

int lcm(int num1, int num2)
{
    return ((num1 * num2) / gcd(num1, num2));
}

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void print()
    {
        cout << this->numerator << "/" << this->denominator << endl;
    }

    void add(Fraction const &f) // this parameter type is very important &operator is used so that copy of object passed is not made,
    //  we simply reference the same object and const ensures that our method will not modify the passed reference object, it is very useful and best practise of c++
    {

        int lcmOfDenominators = lcm(this->denominator, f.denominator);
        int x = this->numerator * (lcmOfDenominators / this->denominator);
        int y = f.numerator * (lcmOfDenominators / f.denominator);
        this->numerator = (x + y);
        this->denominator = lcmOfDenominators;
        this->simplify();
    }

    void multiply(Fraction const &f2)
    {
        this->numerator = this->numerator * f2.numerator;
        this->denominator = this->denominator * f2.denominator;
    }

    void simplify()
    {
        int minVal = min(this->numerator, this->denominator);
        int maxVal = max(this->numerator, this->denominator);
        int gcdOfFraction = gcd(maxVal, minVal);
        this->numerator = this->numerator / gcdOfFraction;
        this->denominator = this->denominator / gcdOfFraction;
    }

    int getNumerator() const
    {
        return this->numerator;
    }

    int getDenominator() const // const keyword make the function constant and it cannot change the value of member variables
    {
        return this->denominator;
    }

    int setNumerator(int numerator)
    {
        this->numerator = numerator;
    }

    int setDenominator(int denominator)
    {
        this->denominator = denominator;
    }

    // Lets learn the operator overloading
    // Operator overloading is a compile time polymorphism
    // We can overload operators like +, -, *, /, ++, --, ==, !=, >, <, >=, <=, <<, >>, =, +=, -=, *=, /=, %=, etc
    // We can overload operators for user defined classes
    // We cannot create new operators, we can only overload existing operators
    // We cannot change the precedence and associativity of operators
    // We cannot overload operators for primitive data types

    // Lets first start by overloading three binary operators +, * and ==

    Fraction operator+(Fraction const &f2) const
    {
        int lcmOfDenominators = lcm(this->denominator, f2.denominator);
        int x = this->numerator * (lcmOfDenominators / this->denominator);
        int y = f2.numerator * (lcmOfDenominators / f2.denominator);
        Fraction fNew(x + y, lcmOfDenominators);
        fNew.simplify();
        return fNew;
    }

    Fraction operator*(Fraction const &f2) const
    {
        Fraction fNew(this->numerator * f2.numerator, this->denominator * f2.denominator);
        fNew.simplify();
        return fNew;
    }

    bool operator==(Fraction const &f2) const
    {
        return (this->numerator == f2.numerator && this->denominator == f2.denominator);
    }

    // Lets overload the unary operator ++ as preincrement operator for Fraction class and ++ as postincrement operator for Fraction class

    Fraction &operator++() // preincrement operator
    {
        this->numerator = this->numerator + this->denominator;
        this->simplify();
        return *this; // Note if we return by value then a copy of object is returned and if we nest the preincrement operator the further operations will be performed on that copy and we will not get expected results,
        // if we return by reference then original object is returned and nesting will work as expected
    }

    Fraction operator++(int) // postincrement operator
    {
        Fraction fNew(this->numerator, this->denominator);
        this->numerator = this->numerator + this->denominator;
        this->simplify();
        return fNew; // here we are returning pass by value as nesting is not required in postincrement operator
    }

    Fraction &operator+=(Fraction const &f2)
    {
        int lcmOfDenominators = lcm(this->denominator, f2.denominator);
        int x = this->numerator * (lcmOfDenominators / this->denominator);
        int y = f2.numerator * (lcmOfDenominators / f2.denominator);
        this->numerator = (x + y);
        this->denominator = lcmOfDenominators;
        this->simplify();
        return *this; // here we want to nest the += operator so we are returning by reference
    }
};

int main()
{

    /*  Fraction f1(15, 4);
     Fraction f2(13, 8);
     f1.print();
     cout << "f1: ";
     f1.print();
     cout << "f2: ";
     f2.print();
     cout << "f1+f2: ";
     f1.multiply(f2);
     f1.print(); */

    /*

    // Constant integers,objects and functions
    constant integer - value of integer cannot be changed
    constant object - value of object cannot be changed (value of member variables cannot be changed)
    constant function - function cannot change the value of member variables
    A contant object can only call constant functions/methods
    For example

     */

    /*   Fraction const f3(10, 3);
      // then
      // f3.setNumerator(10); // this will throw error as setNumerator is not a constant function
      f3.getDenominator(); // this will work as getDenominator is a constant function */

    // lets test the operator overloading

    /*   // Testing the + operator
      Fraction f1(10, 2);
      Fraction f2(15, 4);
      Fraction f3 = f1 + f2;
      f1.print();
      f2.print();
      f3.print(); */

    // Testing the * operator
    /*  Fraction f1(10, 2);
     Fraction f2(15, 4);
     Fraction f3 = f1 * f2;
     f1.print();
     f2.print();
     f3.print(); */

    // Testing the == operator
    /*     Fraction f1(10, 2);
        Fraction f2(15, 4);
        Fraction f3(15, 4);
        if (f1 == f2)
        {
            cout << "f1 and f2 are Equal" << endl;
        }
        else
        {
            cout << "f1 and f2 are Not Equal" << endl;
        }

        if (f1 == f1)
        {
            cout << "f1 and f1 are Equal" << endl;
        }
        else
        {
            cout << "f1 and f1 are Not Equal" << endl;
        } */

    // Testing the preincrement operator
    /* Fraction f1(10, 2);
    Fraction f2 = ++f1;
    f1.print();
    f2.print();
    ++(++f1);
    f1.print(); */

    /* // Testing the postincrement operator
    Fraction f1(10, 2);
    Fraction f2 = f1++;
    f2.print();
    f1.print(); */

    // Testing the += operator
    Fraction f1(10, 2);
    Fraction f2(15, 4);
    (f1 += f2) += f2;
    f1.print();
    f2.print();
}