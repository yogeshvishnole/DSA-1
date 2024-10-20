/*

What is reverse polish notation ?

# Use Cases of Postfix and Prefix Notations

**Postfix** and **Prefix** notations, also known as **Reverse Polish Notation (RPN)** and
**Polish Notation (PN)** respectively, are ways of writing arithmetic expressions without
needing parentheses to dictate operator precedence. They have specific use cases and
advantages in computer science, particularly in the context of compilers, interpreters,
and stack-based calculators.

---

## 1. **Postfix Notation (Reverse Polish Notation - RPN)**

In **Postfix notation**, the operator comes **after** the operands. For example, the
expression `(3 + 4) * 5` in postfix notation would be `3 4 + 5 *`.

### Use Cases:
1. **Evaluation using a Stack**:
   - Postfix expressions can be easily evaluated using a stack. This makes it ideal for use in simple calculators, interpreters, and compilers.
   - Example: The stack-based evaluation of `3 4 + 5 *`:
     1. Push `3` and `4` to the stack.
     2. Encounter `+`: Pop `4` and `3`, add them (`3 + 4 = 7`), and push the result (`7`) back onto the stack.
     3. Push `5` onto the stack.
     4. Encounter `*`: Pop `5` and `7`, multiply them (`7 * 5 = 35`), and push the result (`35`).

2. **No Parentheses Required**:
   - Postfix expressions don't require parentheses to dictate precedence, as the order of operations is strictly determined by the position of the operators and operands.

3. **Used in Postfix Calculators**:
   - Some scientific calculators (like HP's older models) use postfix notation for easier and more efficient computation without needing parentheses or operator precedence rules.

4. **Compilers**:
   - Compilers often convert infix expressions (common notation used by humans) into postfix notation for easier evaluation and code generation.
   - For example, expression trees can be easily traversed to generate postfix output for subsequent evaluation.

5. **Assembly Language and CPU Architectures**:
   - Some CPU architectures and assembly languages (like stack-based machines) use postfix notation to perform arithmetic operations efficiently by pushing and popping operands from the stack.

### Example:
Infix: `(3 + 5) * (8 - 2)`
Postfix: `3 5 + 8 2 - *`

---

## 2. **Prefix Notation (Polish Notation - PN)**

In **Prefix notation**, the operator comes **before** the operands. For example, the expression `(3 + 4) * 5` in prefix notation would be `* + 3 4 5`.

### Use Cases:
1. **Expression Parsing**:
   - Like postfix, prefix notation removes the need for parentheses. However, it makes parsing easier in some recursive-descent parsers (used in compilers) where you process operators first, followed by operands.

2. **Efficient Evaluation without Backtracking**:
   - Prefix notation allows for efficient evaluation of expressions in a single pass from right to left. This is useful in some recursive and functional programming contexts where the structure of the expression is more easily traversed.

3. **Compiler Code Generation**:
   - Prefix notation is often used in intermediate representations of expressions during code generation in compilers. This makes certain optimizations and transformations easier as operators are encountered before operands.

4. **Functional Programming Languages**:
   - Prefix notation is commonly used in functional programming languages (like Lisp) where functions (operators) are applied to arguments (operands) in a consistent structure.
   - Example in Lisp: The sum of 3 and 4 would be written as `(+ 3 4)`.

5. **Tree Traversal**:
   - Prefix notation directly corresponds to the **preorder traversal** of an expression tree. This is useful for evaluating or generating expressions where you first need to apply an operator and then evaluate its operands.

### Example:
Infix: `(3 + 5) * (8 - 2)`
Prefix: `* + 3 5 - 8 2`

---

## Advantages of Postfix and Prefix Notations:
- **No Need for Parentheses**: Both notations eliminate the need for parentheses, making them useful in scenarios where human-readable precedence rules are unnecessary or difficult to enforce.
- **Easier to Parse and Evaluate**: They can be evaluated in a single pass, making them efficient for use in calculators, interpreters, and certain CPU instruction sets.
- **Stack-Friendly**: Both notations are well-suited to stack-based data structures, which makes their evaluation very efficient and fast in stack machines.

---

## Sample Use Case - Evaluation of Postfix Expression using Stack:

For a postfix expression `3 5 + 8 2 - *`, the evaluation using a stack proceeds as follows:
1. **Push** `3` and `5`.
2. **Encounter** `+`: Pop `3` and `5`, compute `3 + 5 = 8`, and **push** `8`.
3. **Push** `8` and `2`.
4. **Encounter** `-`: Pop `8` and `2`, compute `8 - 2 = 6`, and **push** `6`.
5. **Encounter** `*`: Pop `8` and `6`, compute `8 * 6 = 48`.

Final result = `48`.

---

## Conclusion:
- **Postfix** and **Prefix** notations are powerful alternatives to infix notation, especially useful in stack-based systems, compilers, and parsers.
- Postfix is particularly well-suited for stack-based evaluation (as used in many calculators and interpreters), while Prefix is useful in functional programming and recursive evaluation contexts.

Both notations streamline expression evaluation and are crucial in the design of many computational systems.

---


 */

// Evaluating the reverse polish notation

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int evalRPN(vector<string> &tokens)
{
    stack<int> s;

    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
        {
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top();
            s.pop();
            switch (tokens[i][0])
            {
            case '+':
                s.push(operand1 + operand2);
                break;
            case '-':
                s.push(operand1 - operand2);
                break;
            case '*':
                s.push(operand1 * operand2);
                break;
            case '/':
                s.push(operand1 / operand2);
                break;
            }
        }
        else
        {
            s.push(stoi(tokens[i]));
        }
    }

    return s.top();
}

int main() {}