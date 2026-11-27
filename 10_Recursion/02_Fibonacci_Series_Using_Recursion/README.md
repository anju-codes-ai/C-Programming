
# 02 - Fibonacci Series Using Recursion in C

## 📌 Description
This C program generates the Fibonacci series
using a recursive function.

In the Fibonacci series, each number is calculated
by adding the previous two numbers.

Example:
0, 1, 1, 2, 3, 5, 8, 13, 21...

The function `fibonacci()` calls itself to calculate
the next Fibonacci number.

## 🎯 Objective
- Understand recursion using multiple recursive calls.
- Learn how to generate the Fibonacci series.
- Understand base cases in recursion.
- Practise recursive function calls.

## 💻 Function Syntax

```c
int fibonacci(int num)
{
    if (num == 0)
        return 0;

    if (num == 1)
        return 1;

    return fibonacci(num - 1) + fibonacci(num - 2);
}
```

## ⚙️ How It Works
1. The program starts execution from `main()`.
2. The user enters the number of terms.
3. A for loop calls `fibonacci()` for each term.
4. If the number is 0, the function returns 0.
5. If the number is 1, the function returns 1.
6. Otherwise, the function calls itself twice:
   - fibonacci(num - 1)
   - fibonacci(num - 2)
7. Both returned values are added.
8. The Fibonacci series is displayed.

## 🔁 Recursion Flow

For the first six terms:

```text
fibonacci(0) = 0
fibonacci(1) = 1
fibonacci(2) = 1
fibonacci(3) = 2
fibonacci(4) = 3
fibonacci(5) = 5
```

## 📤 Sample Output

```text
Enter number of terms: 8
Fibonacci Series: 0 1 1 2 3 5 8 13
```

## 🧠 Concepts Used
- Recursion
- User-defined functions
- Multiple recursive calls
- Base cases
- For loop
- Return statement
- If statements

## 📊 Function Characteristics

| Property | Description |
|---|---|
| Function Name | fibonacci |
| Arguments | One integer |
| Return Type | int |
| Base Cases | num == 0 and num == 1 |
| Recursive Calls | fibonacci(num - 1), fibonacci(num - 2) |

## ⏱️ Complexity Analysis
- Time Complexity: O(2^n) - Exponential for this
  simple recursive implementation.
- Auxiliary Space Complexity: O(n) - Maximum
  recursion call-stack depth.

## 📚 Learning Outcome
After completing this program, you will understand
how recursion can use multiple recursive calls to
generate a mathematical sequence.

## ⚠️ Important Notes
- The series starts with 0 and 1.
- This program accepts 1 to 40 terms.
- Simple recursive Fibonacci is inefficient for
  large inputs because it repeats calculations.

---
**Part of:** C Programming Practice Repository  
**Category:** Recursion  
**Program:** 02
```

### 4. GitHub folder structure

```text
07_Recursion/
│
├── 01_Factorial_Using_Recursion/
│
└── 02_Fibonacci_Using_Recursion/
    ├── main.c
    └── README.md
```

<badge color="success">2/5 completed</badge>

**Important concept:** Fibonacci recursion uses **two recursive calls** in one function. This is different from factorial, which uses only one recursive call.

**Next:** Program 03 — Sum of Natural Numbers Using Recursion.
