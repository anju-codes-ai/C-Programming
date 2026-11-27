
# 09. Function Call Using Pointers (Call by Reference)

## 📌 Description
This C program demonstrates how pointers are used to modify original variables through a function.

The program passes the memory addresses of two variables to a user-defined function. The function modifies their original values using pointers.

## 🎯 Objective
- Understand pointers with functions.
- Learn address passing.
- Understand modification of original variables.
- Practice dereferencing pointer parameters.

## 💻 Example
Before function call:

First number = 10
Second number = 20

After function call:

First number = 20
Second number = 40

## ⚙️ How It Works
1. The program accepts two integer values.
2. The `calculate()` function is declared with two pointer parameters.
3. The addresses of both variables are passed to the function.
4. The function accesses the original values using `*`.
5. It adds 10 to the first number and 20 to the second.
6. The modified values are displayed in `main()`.

## 🔑 Pointer Logic
```c
void calculate(int *a, int *b)
{
    *a = *a + 10;
    *b = *b + 20;
}
```

Function call:

```c
calculate(&num1, &num2);
```

## 📤 Sample Output
```text
Enter first number: 10
Enter second number: 20

Before function call:
First number = 10
Second number = 20

After function call:
First number = 20
Second number = 40
```

## 🧠 Concepts Used
- Pointers
- Functions
- Pointer parameters
- Address-of operator (&)
- Dereference operator (*)
- Call by reference concept

## ⏱️ Time Complexity
O(1)

## 💾 Space Complexity
O(1) auxiliary space.

## 📚 Learning Outcome
After completing this program, you will understand how a function can modify original variables through pointers.

## ⚠️ Important Note
C technically uses pass by value. In this program, copies of memory addresses are passed to the function, allowing it to modify the original variables through those addresses.

---
**Category:** Pointers  
**Language:** C
