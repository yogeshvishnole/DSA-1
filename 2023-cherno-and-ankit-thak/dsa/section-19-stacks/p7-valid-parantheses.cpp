/*
Valid Parentheses Problem
The Valid Parentheses problem is a classic stack problem. Given a string containing just the
characters '(', ')', '{', '}', '[', and ']', the task is to determine if the input string is
valid. An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.

Example:
Valid: (), ()[]{}
Invalid: (], ([)]

Approach:
1. Use a Stack:
Traverse each character of the string.
For every opening bracket ((, {, [), push it onto the stack.
For every closing bracket (), }, ]):
  Check if the stack is not empty.
  Pop the top of the stack and check if it matches the corresponding opening bracket.
If it doesn’t match, the string is invalid.
At the end, if the stack is empty, the string is valid (all opening brackets had matching
closing brackets).

Edge Cases:
An empty string is considered valid.
If at any point the stack is empty when encountering a closing bracket, the string is invalid.

 */

// soln without using unordered map

#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
    stack<char> stk;

    for (char c : s)
    {
        // If it's an opening bracket, push it onto the stack
        if (c == '(' || c == '{' || c == '[')
        {
            stk.push(c);
        }
        // If it's a closing bracket
        else
        {
            if (stk.empty())
            {
                return false; // Unmatched closing bracket
            }
            char top = stk.top();
            stk.pop();
            // Check if the closing bracket matches the top of the stack
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '['))
            {
                return false; // Mismatched brackets
            }
        }
    }
    // If the stack is empty, all brackets are matched; otherwise, it's invalid
    return stk.empty();
}

int main()
{
    // Test cases
    string test1 = "()[]{}";
    string test2 = "(]";
    string test3 = "([{}])";
    string test4 = "(({{[[}}]]))";

    cout << "Test 1: " << (isValid(test1) ? "Valid" : "Invalid") << endl; // Output: Valid
    cout << "Test 2: " << (isValid(test2) ? "Valid" : "Invalid") << endl; // Output: Invalid
    cout << "Test 3: " << (isValid(test3) ? "Valid" : "Invalid") << endl; // Output: Valid
    cout << "Test 4: " << (isValid(test4) ? "Valid" : "Invalid") << endl; // Output: Invalid

    return 0;
}

/// soln using unordered map

/*

#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValid(string s) {
    // Map to hold the matching pairs of brackets
    unordered_map<char, char> bracketPairs = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    stack<char> stk; // Stack to hold opening brackets

    // Iterate through each character in the string
    for (char c : s) {
        // If it's a closing bracket
        if (bracketPairs.count(c)) {
            // Pop the top element from the stack, or use a dummy value '#' if the stack is empty
            char topElement = stk.empty() ? '#' : stk.top();
            stk.pop();
            // Check if the popped element matches the corresponding opening bracket
            if (topElement != bracketPairs[c]) {
                return false;
            }
        } else {
            // Push opening bracket onto the stack
            stk.push(c);
        }
    }

    // If the stack is empty, the string is valid
    return stk.empty();
}

int main() {
    // Test cases
    string test1 = "()[]{}";
    string test2 = "(]";
    string test3 = "([{}])";
    string test4 = "(({{[[}}]]))";

    cout << "Test 1: " << (isValid(test1) ? "Valid" : "Invalid") << endl;  // Output: Valid
    cout << "Test 2: " << (isValid(test2) ? "Valid" : "Invalid") << endl;  // Output: Invalid
    cout << "Test 3: " << (isValid(test3) ? "Valid" : "Invalid") << endl;  // Output: Valid
    cout << "Test 4: " << (isValid(test4) ? "Valid" : "Invalid") << endl;  // Output: Invalid

    return 0;
}

 */
