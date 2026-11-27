
# 07 - Factorial Using Function

## 📌 Description
This C program calculates the factorial of a given
non-negative integer using a user-defined function.

The function `factorial()` calculates the factorial
using a for loop and returns the result to `main()`.

Factorial is the product of all positive integers
from 1 up to the given number.

Example:
5! = 5 × 4 × 3 × 2 × 1 = 120

By definition:
0! = 1

## 🎯 Objective
- Understand how to use functions with arguments.
- Learn how to return values from a function.
- Practise loops inside user-defined functions.
- Understand factorial calculation.

## 💻 Function Syntax

```c
long long int factorial(int num)
{
    long long int fact = 1;

    for (int i = 1; i <= num; i++)
    {
        fact = fact * i;
    }

    return fact;
}
```

## ⚙️ How It Works
1. The program starts execution from `main()`.
2. The user enters a number.
3. Negative numbers are rejected.
4. The function `factorial()` is called.
5. The number is passed as an argument.
6. A for loop multiplies numbers from 1 to the input.
7. The factorial is returned to `main()`.
8. The result is displayed using `printf()`.

## 📤 Sample Output

```text
Enter a number: 5
Factorial of 5 = 120
```

## 🧠 Concepts Used
- User-defined functions
- Function arguments and parameters
- Return statement
- For loop
- If-else statement
- Factorial logic
- `long long int` data type

## 📊 Function Characteristics

| Property | Description |
|---|---|
| Function Name | factorial |
| Arguments | One integer |
| Return Type | long long int |
| Return Value | Factorial of the number |
| Logic | For loop |

## ⏱️ Time Complexity
O(n) - Linear time, where n is the input number.

## 📚 Learning Outcome
After completing this program, you will understand
how to calculate factorial using a user-defined
function and a loop.

## ⚠️ Note
The `long long int` data type has a limited range.
This program gives correct factorial results for
non-negative integers up to 20.

---
**Part of:** C Programming Practice Repository  
**Category:** Functions  
**Program:** 07
