
# 05 - Greatest of Two Numbers Using Function

## 📌 Description
This C program finds the greatest of two numbers
using a user-defined function.

The program accepts two integers from the user
and passes them to the function `findGreatest()`.
The function compares both numbers and returns
the greater value.

If both numbers are equal, it returns either number.

## 🎯 Objective
- Understand how to use functions for problem-solving.
- Practise passing arguments to a function.
- Learn how to return a calculated result.
- Apply conditional statements inside a function.

## 💻 Function Syntax

```c
int functionName(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
```

## ⚙️ How It Works
1. The program starts execution from `main()`.
2. The user enters two numbers.
3. The function `findGreatest()` is called.
4. Both numbers are passed as arguments.
5. The function compares the two values using `if-else`.
6. The greater number is returned to `main()`.
7. The result is displayed on the screen.

## 📤 Sample Output

```text
Enter first number: 45
Enter second number: 30
Greatest number = 45
```

## 🧠 Concepts Used
- User-defined functions
- Function arguments and parameters
- Return statement
- If-else-if conditional statements
- Integer data type
- Comparison operators

## 📊 Function Characteristics

| Property | Description |
|---|---|
| Function Name | findGreatest |
| Arguments | Two integers |
| Return Type | int |
| Return Value | Greatest number |
| Logic | If-else comparison |

## ⏱️ Time Complexity
O(1) - Constant time.

## 📚 Learning Outcome
After completing this program, you will understand
how to use a function with arguments and a return
value to solve a comparison-based problem.

---
**Part of:** C Programming Practice Repository  
**Category:** Functions  
**Program:** 05
