
# 03 - Function with No Arguments and Return Value

## 📌 Description
This C program demonstrates a user-defined function
that does not accept any arguments but returns a value.

The function `addNumbers()` takes two numbers from
the user, calculates their sum, and returns the result
to the calling function (`main()`).

## 🎯 Objective
- Understand functions that return values.
- Learn the use of the `return` statement.
- Understand functions without arguments.
- Learn how to receive a returned value in a variable.

## 💻 Function Syntax

```c
return_type functionName(void)
{
    // Statements
    return value;
}
```

## ⚙️ How It Works
1. The program starts execution from `main()`.
2. The function `addNumbers()` is declared with return type `int`.
3. The function is called from `main()`.
4. The function accepts no arguments.
5. Two numbers are entered inside the function.
6. The function calculates their sum.
7. The `return` statement sends the result to `main()`.
8. The returned value is stored in the variable `result`.

## 📤 Sample Output

```text
Enter first number: 15
Enter second number: 25
Sum = 40
```

## 🧠 Concepts Used
- User-defined functions
- Function declaration
- Function definition
- Function calling
- Return type
- `return` statement
- `scanf()` and `printf()`

## 📊 Function Characteristics

| Property | Description |
|---|---|
| Function Name | addNumbers |
| Arguments | No arguments |
| Return Type | int |
| Return Value | Sum of two numbers |
| Return Statement | return a + b; |

## ⏱️ Time Complexity
O(1) - Constant time.

## 📚 Learning Outcome
After completing this program, you will understand
how a function can return a value to the calling
function without receiving any arguments.

---
**Part of:** C Programming Practice Repository  
**Category:** Functions  
**Program:** 03
