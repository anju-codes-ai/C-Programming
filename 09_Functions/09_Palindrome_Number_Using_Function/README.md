
# 09 - Palindrome Number Using Function

## 📌 Description
This C program checks whether a given integer is
a palindrome number using a user-defined function.

A palindrome number is a number that remains the
same when its digits are reversed.

Example:
121 → Reverse = 121 → Palindrome

123 → Reverse = 321 → Not Palindrome

The function `isPalindrome()` reverses the number
and compares it with the original number.

## 🎯 Objective
- Understand functions with arguments and return values.
- Learn how to reverse a number.
- Practise while loops.
- Understand palindrome logic.
- Learn how to return a condition from a function.

## 💻 Function Syntax

```c
int isPalindrome(int num)
{
    int original = num;
    int reverse = 0;

    while (num > 0)
    {
        int digit = num % 10;
        reverse = reverse * 10 + digit;
        num = num / 10;
    }

    return original == reverse;
}
```

## ⚙️ How It Works
1. The program starts execution from `main()`.
2. The user enters an integer.
3. The function `isPalindrome()` is called.
4. The original number is stored in a variable.
5. A while loop extracts digits using `% 10`.
6. The reversed number is constructed.
7. The original number is compared with the reversed number.
8. The function returns 1 if both are equal; otherwise, it returns 0.
9. The result is displayed using if-else.

## 📤 Sample Output

```text
Enter a number: 121
121 is a Palindrome number.
```

## 🧠 Concepts Used
- User-defined functions
- Function arguments and parameters
- Integer return type
- Return statement
- While loop
- If-else statement
- Modulus operator (%)
- Division operator (/)

## 📊 Function Characteristics

| Property | Description |
|---|---|
| Function Name | isPalindrome |
| Arguments | One integer |
| Return Type | int |
| Return Value | 1 for palindrome, 0 otherwise |
| Logic | Number reversal and comparison |

## ⏱️ Time Complexity
O(d) - Linear time, where d is the number of digits.

## 📚 Learning Outcome
After completing this program, you will understand
how to reverse a number and check palindrome logic
using a user-defined function.

## ⚠️ Important Notes
- Negative numbers are treated as non-palindromes.
- A single-digit non-negative number is a palindrome.
- 0 is also a palindrome.

---
**Part of:** C Programming Practice Repository  
**Category:** Functions  
**Program:** 09
