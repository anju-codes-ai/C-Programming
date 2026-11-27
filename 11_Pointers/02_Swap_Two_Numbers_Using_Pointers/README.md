
# 02. Swap Two Numbers Using Pointers

## 📌 Description
This C program swaps two numbers using pointers and a user-defined function.

It demonstrates how pointers allow a function to modify the original variables by accessing their memory addresses.

## 🎯 Objective
- Understand pointers in C.
- Learn call by reference.
- Pass addresses to a function.
- Swap values using pointer variables.

## 💻 Example
Before swapping:

First number = 10  
Second number = 20

After swapping:

First number = 20  
Second number = 10

## ⚙️ How It Works
1. The program accepts two numbers from the user.
2. The `swap()` function receives their addresses.
3. A temporary variable stores the first value.
4. The first variable receives the second value.
5. The second variable receives the temporary value.
6. The swapped values are displayed.

## 🔁 Swapping Logic
```c
temp = *a;
*a = *b;
*b = temp;
```

## 📤 Sample Output
```text
Enter first number: 10
Enter second number: 20

Before swapping:
First number = 10
Second number = 20

After swapping:
First number = 20
Second number = 10
```

## 🧠 Concepts Used
- Pointers
- Pointer declaration
- Address-of operator (&)
- Dereference operator (*)
- User-defined functions
- Call by reference
- Temporary variable

## ⏱️ Time Complexity
O(1)

## 💾 Space Complexity
O(1)

## 📚 Learning Outcome
After completing this program, you will understand how pointers can modify original variables through a function.

## ⭐ Important Note
C uses pass by value. Passing addresses to a function allows it to modify the original variables through pointers.

---
**Category:** Pointers  
**Language:** C
