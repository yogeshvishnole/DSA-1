/*

Leetcode link - https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/submissions/1427486499/

You are given a string s consisting of lowercase English letters. A duplicate removal
consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made.
It can be proven that the answer is unique.

Example 1:

Input: s = "abbaca"
Output: "ca"
Explanation:
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal,
and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

Input: s = "azxxzy"
Output: "ay"

Approach 1 -

Approach 1: Using Stack
Idea:
A stack is well-suited for this problem because it allows us to efficiently keep track of the
last character we have seen and compare it with the current character.
We'll iterate through the string, and for each character:
If the stack is empty or the top of the stack is not the same as the current character, push
the character onto the stack.
If the top of the stack is the same as the current character, pop the stack (since we found
adjacent duplicates).
Steps:
1. Initialize an empty stack.
2. Traverse the string character by character.
3. Push the character onto the stack if the stack is empty or if the top of the stack is not the
same as the current character.
4. If the top of the stack is the same as the current character, pop the stack to remove the
duplicate.
5. After the loop, convert the stack to a string by popping characters from it and then
reverse the string
Time Complexity:
O(n), where n is the length of the string since each character is pushed and popped at most
once.
Space Complexity = O(n) for stack

Approach 2 more efficient than 1 in terms of space - Simulate inplace stack in given string
using top pointer;

1. initialize the stack pointer with -1
2. Traverse the string character by character.
3. if stack pointer is -1 OR element at stack pointer is not equal to the current element
increment the stack pointer.,put the current character at the new poisition of stack
pointer
4. if element at stack pointer is equal to the current element than decrement the stack
pointer.
5. copy the original string value till stack pointer in a ans string.


 */

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

// Approach 1
string removeAdjacentDuplicates(string s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (st.empty() || st.top() != s[i])
        {
            st.push(s[i]);
        }
        else
        {
            st.pop();
        }
    }

    string ans = "";
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// Approach 2
string removeAdjacentDuplicates2(string s)
{
    int stackPtr = -1;

    for (int i = 0; i < s.length(); i++)
    {
        if (stackPtr == -1 || s[stackPtr] != s[i])
        {
            stackPtr++;
            s[stackPtr] = s[i];
        }
        else
        {
            stackPtr--;
        }
    }
    string ans = "";
    for (int i = 0; i <= stackPtr; i++)
    {
        ans += s[i];
    }
    return ans;
}

int main()
{
    string inputString = "abbaca";
    cout << removeAdjacentDuplicates2(inputString) << endl;
}
