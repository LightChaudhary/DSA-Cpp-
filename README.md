**This repository contains DSA implementations using C++.**
I will push code and concepts for Stack, Queue, Recursion, List, Tree, Graph, Sorting, and Searching.
Each topic includes clean implementations and simple explanations.

# Stack
### Stack Using Array (Manual Capacity)

This program implements a simple stack in C++ using a manually defined capacity.
The stack uses a dynamic array and an integer top index.
Supported operations: push, pop, peek, isFull, isEmpty.
It also handles overflow and underflow conditions properly.
The example pushes 10, 20, 30 and prints them in LIFO order.
Useful for learning basic stack operations and array-based implementation.

### Infix to Postfix Conversion Using Stack

This program converts an infix expression into postfix using a stack.
Stack is implemented with a static char array.
Handles operands, operators, parentheses, and precedence.
Implements push, pop, peek operations internally.
Supports operators: +, -, *, /, ^.
User inputs an infix expression, program outputs postfix.
Scans expression from left to right.

### Evaluation of Postfix Expression

This program calculates the postfix expression and returns a single value.
Stack is implemented using STL. 
Handles operands and operators from left to right.
User inputs an postfix expressoin, program outputs single value.

### Evaluation of Prefix Expression

This program calculates the prefix expression and returns a single value.
Stack is implemented using STL. 
Handles operands and operators from right to left.
User inputs an prefix expressoin, program outputs single value.

### Infix to Prefix Conversion Using Stack

This program converts an infix expression into prefix using a stack.
Stack is implemented with a static char arrar.
Handles operands, operators, parentheses, and precedence.
Implements push, pop, peek operations internally.
Supports operators: +, -, *, /, ^.
User inputs an infix expression, program outputs prefix.
Scans expression from right to left.
