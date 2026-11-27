
# 04 - Function with Arguments and Return Value

## 📌 Description
This C program demonstrates a user-defined function
that accepts arguments and returns a value.

The program takes two numbers from the user and
passes them to the function `addNumbers()`.
The function calculates their sum and returns the
result to the calling function (`main()`).

## 🎯 Objective
- Understand functions with arguments and return values.
- Learn how to pass values to a function.
- Understand function parameters.
- Learn how to return results using the `return` statement.
- Practise reusable function design.

## 💻 Function Syntax

```c
return_type functionName(data_type parameter1,
                         data_type parameter2)
{
    // Statements
    return value;
}
```

## ⚙️ How It Works
1. The program starts execution from `main()`.
2. Two numbers are entered by the user.
3. The function `addNumbers()` is called with both numbers.
4. The values are received by parameters `a` and `b`.
5. The function calculates their sum.
6. The `return` statement sends the sum back to `main()`.
7. The returned result is stored in the variable `result`.
8. The sum is displayed using `printf()`.

## 📤 Sample Output

```text
Enter first number: 20
Enter second number: 30
Sum = 50
```

## 🧠 Concepts Used
- User-defined functions
- Function arguments
- Function parameters
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
| Arguments | Two integers |
| Parameters | int a, int b |
| Return Type | int |
| Return Value | Sum of two numbers |

## ⏱️ Time Complexity
O(1) - Constant time.

## 📚 Learning Outcome
After completing this program, you will understand
how to pass arguments to a function and return a
calculated value to the calling function.

---
**Part of:** C Programming Practice Repository  
**Category:** Functions  
**Program:** 04
