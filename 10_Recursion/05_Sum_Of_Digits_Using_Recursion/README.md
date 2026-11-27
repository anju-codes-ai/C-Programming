
# 05. Sum of Digits Using Recursion

## 📌 Description
This C program calculates the sum of all digits of a number using recursion.

The program takes a non-negative integer as input and adds its digits using a recursive function.

## 🎯 Objective
- Understand recursion in C.
- Learn how to extract digits from a number.
- Practice recursive function calls.
- Understand base cases.

## 💻 Example
Number = 1234

Sum = 1 + 2 + 3 + 4

Result = 10

## ⚙️ How It Works
1. The program accepts a number from the user.
2. The `sumOfDigits()` function checks whether the number is zero.
3. If the number is zero, it returns 0.
4. Otherwise, it extracts the last digit using `% 10`.
5. It removes the last digit using `/ 10`.
6. The function repeats the process recursively.
7. Finally, it returns the sum of all digits.

## 🔁 Recursion Logic
```c
if (num == 0)
{
    return 0;
}

return (num % 10) + sumOfDigits(num / 10);
```

## 📤 Sample Output
```text
Enter a number: 1234
Sum of digits = 10
```

## 🧠 Concepts Used
- Recursion
- User-defined functions
- Base case
- Recursive calls
- Modulus operator
- Integer division

## ⏱️ Time Complexity
O(d), where d is the number of digits.

## 💾 Space Complexity
O(d), due to recursive function calls.

## 📚 Learning Outcome
After completing this program, you will understand how recursion can be used to process individual digits of a number.

## ⚠️ Important Note
- This program accepts non-negative integers only.
- The sum must fit within the `int` data type.

---
**Category:** Recursion  
**Language:** C
