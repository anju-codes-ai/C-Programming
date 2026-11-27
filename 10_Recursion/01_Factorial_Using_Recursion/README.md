
# 01 - Factorial Using Recursion in C

## 📌 Description
This C program calculates the factorial of a
number using recursion.

Recursion is a programming technique in which
a function calls itself to solve a problem.

The function `factorial()` repeatedly calls itself
with a smaller number until it reaches the base case.

Example:
5! = 5 × 4 × 3 × 2 × 1 = 120

## 🎯 Objective
- Understand the concept of recursion in C.
- Learn how a function calls itself.
- Understand base cases and recursive cases.
- Calculate factorial using recursion.

## 💻 Function Syntax

```c
long long int factorial(int num)
{
    if (num == 0 || num == 1)
    {
        return 1;
    }

    return num * factorial(num - 1);
}
```

## ⚙️ How It Works
1. The program starts execution from `main()`.
2. The user enters a non-negative integer.
3. The function `factorial()` is called.
4. If the number is 0 or 1, the function returns 1.
5. Otherwise, the function calls itself with `num - 1`.
6. Each call multiplies the current number by
   the result of the next recursive call.
7. The final result is returned to `main()`.

## 🔁 Recursion Flow

For input 5:

```text
factorial(5)
= 5 × factorial(4)
= 5 × 4 × factorial(3)
= 5 × 4 × 3 × factorial(2)
= 5 × 4 × 3 × 2 × factorial(1)
= 5 × 4 × 3 × 2 × 1
= 120
```

## 📤 Sample Output

```text
Enter a number: 5
Factorial of 5 = 120
```

## 🧠 Concepts Used
- Recursion
- User-defined functions
- Base case
- Recursive case
- Function calling
- Return statement
- If statement

## 📊 Function Characteristics

| Property | Description |
|---|---|
| Function Name | factorial |
| Arguments | One integer |
| Return Type | long long int |
| Base Case | num == 0 or num == 1 |
| Recursive Call | factorial(num - 1) |

## ⏱️ Complexity Analysis
- Time Complexity: O(n)
- Auxiliary Space Complexity: O(n) due to recursive calls.

## 📚 Learning Outcome
After completing this program, you will understand
how recursion works, why a base case is necessary,
and how a recursive function returns its final result.

## ⚠️ Important Notes
- Factorial of 0 is 1.
- Factorial is not defined for negative integers.
- This program accepts values from 0 to 20 to
  stay within the range of `long long int`.

---
**Part of:** C Programming Practice Repository  
**Category:** Recursion  
**Program:** 01
