
# 10 - Sum of Digits Using Function

## 📌 Description
This C program calculates the sum of all digits
of a given integer using a user-defined function.

The program accepts a number from the user and
passes it to the function `sumOfDigits()`.

The function extracts each digit, adds it to the
sum, and returns the final result to `main()`.

Example:
1234 = 1 + 2 + 3 + 4 = 10

## 🎯 Objective
- Understand functions with arguments and return values.
- Learn how to extract digits from a number.
- Practise while loops inside functions.
- Understand the modulus and division operators.
- Learn how to return calculated results.

## 💻 Function Syntax

```c
int sumOfDigits(int num)
{
    int sum = 0;

    while (num > 0)
    {
        int digit = num % 10;
        sum = sum + digit;
        num = num / 10;
    }

    return sum;
}
```

## ⚙️ How It Works
1. The program starts execution from `main()`.
2. The user enters an integer.
3. The function `sumOfDigits()` is called.
4. The number is passed as an argument.
5. The modulus operator `% 10` extracts the last digit.
6. The extracted digit is added to the variable `sum`.
7. The division operator `/ 10` removes the last digit.
8. The loop continues until the number becomes 0.
9. The function returns the final sum to `main()`.
10. The result is displayed using `printf()`.

## 📤 Sample Output

```text
Enter a number: 1234
Sum of digits = 10
```

## 🧠 Concepts Used
- User-defined functions
- Function arguments and parameters
- Integer return type
- Return statement
- While loop
- Modulus operator (%)
- Division operator (/)
- If statement

## 📊 Function Characteristics

| Property | Description |
|---|---|
| Function Name | sumOfDigits |
| Arguments | One integer |
| Return Type | int |
| Return Value | Sum of all digits |
| Logic | Digit extraction using while loop |

## ⏱️ Time Complexity
O(d) - Linear time, where d is the number of digits.

## 📚 Learning Outcome
After completing this program, you will understand
how to extract digits, calculate their sum, and
return the result using a user-defined function.

## ⚠️ Important Notes
- The program also handles negative input by using its positive value.
- For input 0, the sum of digits is 0.
- The result is stored in an integer, so extremely large inputs may exceed the supported range.

---
**Part of:** C Programming Practice Repository  
**Category:** Functions  
**Program:** 10
