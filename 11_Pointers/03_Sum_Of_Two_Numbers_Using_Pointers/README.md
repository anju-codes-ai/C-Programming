
# 03. Sum of Two Numbers Using Pointers

## 📌 Description
This C program calculates the sum of two numbers using pointers.

It demonstrates how pointer variables can access the values of other variables through their memory addresses.

## 🎯 Objective
- Understand pointer variables.
- Learn how to store memory addresses.
- Access values using dereferencing.
- Perform arithmetic operations using pointers.

## 💻 Example
First number = 15  
Second number = 25  

Sum = 15 + 25 = 40

## ⚙️ How It Works
1. The program accepts two integer values.
2. Two pointer variables are declared.
3. The addresses of the numbers are assigned to the pointers.
4. The dereference operator (*) accesses the original values.
5. Both values are added.
6. The final sum is displayed.

## 🔑 Pointer Logic
```c
ptr1 = &num1;
ptr2 = &num2;

sum = *ptr1 + *ptr2;
```

## 📤 Sample Output
```text
Enter first number: 15
Enter second number: 25
First number = 15
Second number = 25
Sum = 40
```

## 🧠 Concepts Used
- Pointers
- Pointer declaration
- Address-of operator (&)
- Dereference operator (*)
- Integer variables
- Arithmetic operations

## ⏱️ Time Complexity
O(1)

## 💾 Space Complexity
O(1)

## 📚 Learning Outcome
After completing this program, you will understand how pointers can access variable values and perform calculations.

---
**Category:** Pointers  
**Language:** C
