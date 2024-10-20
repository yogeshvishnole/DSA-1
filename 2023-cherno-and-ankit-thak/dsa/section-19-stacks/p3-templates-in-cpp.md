# Templates in C++

- [Function Templates](#1-function-templates)
- [Class Templates](#2-class-templates)
- [Pair Class Using Templates](#implementing-the-pair-class-using-templates-similar-to-stdpair-in-stl)
- [Template Specialization](#template-specialization)
- [Variadic Templates](#variadic-templates-advanced)
- [Conclusion](#conclusion)

---

# Templates in C++

Templates in C++ are a powerful feature that allows you to write generic and reusable code. Instead of writing separate functions or classes for each data type, you can write a **template** that works with any data type.

## Types of Templates:

1. **Function Templates**: For writing generic functions.
2. **Class Templates**: For writing generic classes or data structures.

## Why Use Templates?

Templates help in writing code that can:

- Work with any data type (integers, floating-point numbers, objects, etc.).
- Reduce redundancy by avoiding writing the same logic multiple times for different types.
- Ensure type safety and code reusability.

---

## 1. Function Templates

A **function template** allows you to create a function that works with different data types without having to specify the type explicitly.

### Example (Function Template):

```cpp
#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << "Addition of integers: " << add(3, 4) << endl;      // Works with int
    cout << "Addition of doubles: " << add(3.5, 4.5) << endl;  // Works with double
    return 0;
}
```

---

## 2. Class Templates

A **class template** allows you to create a class that works with different data types in a similar manner.

### Example (Class Template):

```cpp
#include <iostream>
using namespace std;

template <typename T>
class Box {
    T value;

public:
    Box(T val) : value(val) {}

    T getValue() {
        return value;
    }
};

int main() {
    Box<int> intBox(10);         // Box of type int
    Box<double> doubleBox(20.5); // Box of type double

    cout << "Integer Box: " << intBox.getValue() << endl;
    cout << "Double Box: " << doubleBox.getValue() << endl;

    return 0;
}
```

---

## Implementing the `pair` Class Using Templates (Similar to `std::pair` in STL)

In the Standard Template Library (STL), the `pair` class holds two values of potentially different types. We can create a similar `pair` class using templates.

### Code Example: `pair` Class Using Templates

```cpp
#include <iostream>
using namespace std;

// Template class for Pair
template <typename T1, typename T2>
class Pair {
    T1 first;
    T2 second;

public:
    // Constructor
    Pair(T1 firstValue, T2 secondValue) : first(firstValue), second(secondValue) {}

    // Getters for first and second elements
    T1 getFirst() const {
        return first;
    }

    T2 getSecond() const {
        return second;
    }

    // Setter for first element
    void setFirst(T1 value) {
        first = value;
    }

    // Setter for second element
    void setSecond(T2 value) {
        second = value;
    }

    // Display Pair values
    void display() const {
        cout << "(" << first << ", " << second << ")" << endl;
    }
};

int main() {
    // Pair of int and string
    Pair<int, string> pair1(1, "One");
    pair1.display();  // Output: (1, One)

    // Pair of double and char
    Pair<double, char> pair2(3.14, 'A');
    pair2.display();  // Output: (3.14, A)

    // Modify the first and second values of pair1
    pair1.setFirst(100);
    pair1.setSecond("Hundred");
    pair1.display();  // Output: (100, Hundred)

    return 0;
}
```

---

## Template Specialization

Sometimes, you may want a specific behavior for certain data types. C++ provides **template specialization** for this.

### Example (Template Specialization):

```cpp
#include <iostream>
using namespace std;

template <typename T>
class Calculator {
public:
    T add(T a, T b) {
        return a + b;
    }
};

// Specialization for string types
template <>
class Calculator<string> {
public:
    string add(string a, string b) {
        return a + " " + b; // Concatenates strings with a space
    }
};

int main() {
    Calculator<int> intCalc;
    cout << "Int addition: " << intCalc.add(3, 4) << endl;  // Output: 7

    Calculator<string> stringCalc;
    cout << "String addition: " << stringCalc.add("Hello", "World") << endl;  // Output: Hello World

    return 0;
}
```

---

## Variadic Templates (Advanced)

Variadic templates allow templates to accept an arbitrary number of template parameters, making them extremely flexible.

### Example (Variadic Template):

```cpp
#include <iostream>
using namespace std;

// Base case for recursion
void print() {}

// Variadic template function
template <typename T, typename... Args>
void print(T first, Args... args) {
    cout << first << " ";
    print(args...); // Recursively calls with remaining arguments
}

int main() {
    print(1, 2.5, "Hello", 'A');  // Output: 1 2.5 Hello A
    return 0;
}
```

---

## Conclusion

Templates in C++ are a versatile and powerful feature, allowing you to write generic, reusable code. They are widely used in the **STL** for containers and algorithms and are essential for writing type-safe and efficient code.

Key features include:

- **Function Templates**: For generic functions.
- **Class Templates**: For creating data structures and classes that work with any data type.
- **Specialization**: For handling specific cases for certain data types.
- **Variadic Templates**: For accepting multiple template parameters.
