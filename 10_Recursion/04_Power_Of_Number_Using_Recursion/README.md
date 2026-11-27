
# 04. Power of a Number Using Recursion

## 📌 Description
This C program calculates the power of a number using recursion.

It takes a base and a non-negative exponent from the user and calculates the result through recursive function calls.

## 🎯 Objective
- Understand recursion in C.
- Learn how to calculate powers using a recursive function.
- Understand base cases and recursive calls.

## 💻 Example
Base = 2  
Exponent = 5  

Result = 2 × 2 × 2 × 2 × 2 = 32

## ⚙️ How It Works
1. The program takes the base and exponent as input.
2. The `power()` function checks whether the exponent is zero.
3. If exponent is zero, it returns 1.
4. Otherwise, it multiplies the base by the recursive result.
5. The final result is displayed.

## 🔁 Recursion Logic
```c
if (exponent == 0)
{
    return 1;
}

return base * power(base, exponent - 1);
```

## 📤 Sample Output
```text
Enter the base: 2
Enter the exponent: 5
2 raised to power 5 = 32
```

## 🧠 Concepts Used
- Recursion
- User-defined functions
- Base case
- Recursive calls
- Function return values
- Conditional statements

## ⏱️ Time Complexity
O(n), where n is the exponent.

## 💾 Space Complexity
O(n), due to recursive function calls.

## 📚 Learning Outcome
After completing this program, you will understand how recursion can be used to calculate the power of a number.

## ⚠️ Important Note
- This program supports non-negative integer exponents only.
- The result must fit within the `long long int` range.
- In C, `^` is the bitwise XOR operator, not the power operator.

---
**Category:** Recursion  
**Language:** C
