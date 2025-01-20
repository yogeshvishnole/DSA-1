/*
Usecase of iterators

Iterators in C++ are powerful tools for working with containers (like vector, map, set, etc.) and provide a consistent way to traverse and manipulate their elements. Below are the key use cases for iterators in C++:

1. Traversing Containers
Iterators allow sequential traversal of elements in any container, regardless of its underlying implementation.
Example: Traversing vector, map, or unordered_map elements in a unified manner.

std::vector<int> vec = {1, 2, 3, 4};
for (auto it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << " ";  // Dereference to access the value
}
2. Abstracting Container Access
Iterators provide an abstract interface for working with containers. You don't need to know how elements are stored internally (array, linked list, etc.).
Example: The same iterator syntax can be used for vector, set, or map.

template <typename Container>
void printElements(const Container &c) {
    for (auto it = c.begin(); it != c.end(); ++it) {
        std::cout << *it << " ";
    }
}
3. Modifying Container Elements
Iterators can be used to modify container elements during traversal.

std::vector<int> vec = {1, 2, 3};
for (auto it = vec.begin(); it != vec.end(); ++it) {
    *it *= 2;  // Multiply each element by 2
}
4. Erasing Elements During Iteration
Using iterators, you can safely remove elements from a container during traversal without breaking the loop.

std::vector<int> vec = {1, 2, 3, 4};
for (auto it = vec.begin(); it != vec.end();) {
    if (*it % 2 == 0) {  // Remove even numbers
        it = vec.erase(it);
    } else {
        ++it;
    }
}
5. Accessing Non-Sequential Containers
For containers like map, unordered_map, or set, iterators provide access to elements in the required order (sorted for map, arbitrary for unordered_map).

std::map<int, std::string> myMap = {{1, "One"}, {2, "Two"}};
for (auto it = myMap.begin(); it != myMap.end(); ++it) {
    std::cout << it->first << ": " << it->second << std::endl;  // Access key-value pairs
}
6. Backwards Traversal
Reverse iterators (rbegin, rend) allow traversal of elements in reverse order.

std::vector<int> vec = {10, 20, 30};
for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
    std::cout << *it << " ";  // Output: 30 20 10
}
7. Using Iterator Methods (find, insert, erase)
Many STL containers provide methods that use iterators for efficient operations.

std::map<int, std::string> myMap = {{1, "One"}, {2, "Two"}};

// Find an element
auto it = myMap.find(2);
if (it != myMap.end()) {
    std::cout << "Found: " << it->second << std::endl;
}

// Erase an element
myMap.erase(it);
8. Custom Container Iteration
Iterators are essential for custom container implementations. By defining begin() and end() methods, you can make your container iterable.
9. Algorithm Compatibility
Standard algorithms (std::sort, std::find, etc.) work with iterators, enabling generic programming.

#include <algorithm>
std::vector<int> vec = {3, 1, 4, 2};
std::sort(vec.begin(), vec.end());  // Sort the vector
10. Efficiency
Iterators eliminate the need for index-based access (e.g., vec[i]), which can be inefficient for certain containers (e.g., linked lists).
Summary:
Iterators are used for:

Traversing, modifying, and erasing container elements.
Abstracting access to different container types.
Supporting generic algorithms.
Efficient handling of non-sequential and custom containers.
By using iterators, you write cleaner, more generic, and container-agnostic code that can adapt to various STL containers and custom types.














 */

#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>

int main()
{
    /*
    ================================================
    1. ITERATORS IN VECTOR
    - A `vector` is a dynamic array in C++.
    - Iterators allow sequential traversal of the elements.
    - We use `.begin()` for the first element and `.end()` for one past the last element.
    ================================================
    */
    std::vector<int> vec = {10, 20, 30, 40, 50};
    std::cout << "Vector Elements:" << std::endl;

    // Using explicit iterator
    std::vector<int>::iterator it;
    for (it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << " "; // Dereference to access value
    }
    std::cout << std::endl;

    // Optimized way using `auto`
    std::cout << "Using auto:" << std::endl;
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    /*
    Methods on vector with iterators:
    - `.erase(iterator)` removes an element at the iterator's position.
    - `.erase(iterator, iterator)` removes a range of elements.
    */
    std::cout << "Erasing an element from vector:" << std::endl;
    vec.erase(vec.begin() + 2); // Erase the third element (30)
    for (auto val : vec)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    /*
    ================================================
    2. ITERATORS IN MAP
    - A `map` stores key-value pairs in sorted order (based on keys).
    - Iterators allow traversal of the elements in sorted order.
    ================================================
    */
    std::map<int, std::string> ordered_map = {{1, "One"}, {2, "Two"}, {3, "Three"}};
    std::cout << "Map Elements:" << std::endl;

    for (auto it = ordered_map.begin(); it != ordered_map.end(); ++it)
    {
        std::cout << it->first << ": " << it->second << std::endl; // Access key and value
    }

    /*
    Methods on map with iterators:
    - `.find(key)` returns an iterator to the element with the specified key or `.end()` if the key is not found.
    - `.erase(iterator)` removes the element at the iterator's position.
    */
    auto map_it = ordered_map.find(2); // Find the key `2`
    if (map_it != ordered_map.end())
    {
        std::cout << "Found key 2 with value: " << map_it->second << std::endl;
    }

    std::cout << "Erasing key 2 from map:" << std::endl;
    ordered_map.erase(map_it); // Erase the key-value pair with key 2
    for (auto &pair : ordered_map)
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    /*
    ================================================
    3. ITERATORS IN UNORDERED_MAP
    - An `unordered_map` stores key-value pairs in no specific order.
    - It provides faster average-case lookups compared to `map` (O(1) vs O(log n)).
    ================================================
    */
    std::unordered_map<std::string, int> unordered_map = {{"Alice", 25}, {"Bob", 30}, {"Charlie", 35}};
    std::cout << "Unordered Map Elements:" << std::endl;

    for (auto it = unordered_map.begin(); it != unordered_map.end(); ++it)
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    /*
    Methods on unordered_map with iterators:
    - `.find(key)` works similarly to `map`, returning an iterator to the key-value pair if the key exists or `.end()` otherwise.
    - `.erase(iterator)` removes the element at the iterator's position.
    */
    auto unordered_it = unordered_map.find("Bob"); // Find key "Bob"
    if (unordered_it != unordered_map.end())
    {
        std::cout << "Found Bob with age: " << unordered_it->second << std::endl;
    }

    std::cout << "Erasing Bob from unordered_map:" << std::endl;
    unordered_map.erase(unordered_it); // Erase "Bob"
    for (const auto &pair : unordered_map)
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
