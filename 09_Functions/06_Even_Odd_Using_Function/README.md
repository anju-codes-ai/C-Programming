
# 06 - Even or Odd Using Function

## 📌 Description
This C program checks whether a given integer is
even or odd using a user-defined function.

The program accepts a number from the user and
passes it to the function `checkEvenOdd()`.
The function checks whether the number is divisible
by 2 and displays the result.

## 🎯 Objective
- Understand how to use functions for checking conditions.
- Learn how to pass arguments to a function.
- Practise if-else statements inside a function.
- Understand the modulus operator.

## 💻 Function Syntax

```c
void functionName(int num)
{
    if (num % 2 == 0)
    {
        // Even number
    }
    else
    {
        // Odd number
    }
}
```

## ⚙️ How It Works
1. The program starts execution from `main()`.
2. The user enters an integer.
3. The function `checkEvenOdd()` is called.
4. The number is passed as an argument.
5. The function uses the modulus operator `%`.
6. If the remainder is 0, the number is even.
7. Otherwise, the number is odd.
8. The result is displayed on the screen.

## 📤 Sample Output

```text
Enter a number: 24
24 is an Even number.
```

## 🧠 Concepts Used
- User-defined functions
- Function arguments and parameters
- Function declaration and definition
- Function calling
- If-else statements
- Modulus operator (%)
- `printf()` and `scanf()`

## 📊 Function Characteristics

| Property | Description |
|---|---|
| Function Name | checkEvenOdd |
| Arguments | One integer |
| Return Type | void |
| Return Value | No value |
| Logic | Modulus and if-else |

## ⏱️ Time Complexity
O(1) - Constant time.

## 📚 Learning Outcome
After completing this program, you will understand
how to use a user-defined function with arguments
to check a number using conditional statements.

---
**Part of:** C Programming Practice Repository  
**Category:** Functions  
**Program:** 06
