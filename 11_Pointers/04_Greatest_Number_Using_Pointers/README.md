
# 04. Greatest Number Using Pointers

## 📌 Description
This C program finds the greatest among three numbers using pointers.

It uses pointer variables to access the values of three integer variables and compares them using conditional statements.

## 🎯 Objective
- Understand pointers in C.
- Access variable values using pointers.
- Perform comparisons using dereferencing.
- Practice conditional statements with pointers.

## 💻 Example
First number = 25  
Second number = 70  
Third number = 45  

Greatest number = 70

## ⚙️ How It Works
1. The program accepts three integer values.
2. Three pointer variables are declared.
3. Each pointer stores the address of one number.
4. The dereference operator (*) accesses the values.
5. Conditional statements compare the three values.
6. The greatest number is displayed.

## 🔑 Pointer Logic
```c
ptr1 = &num1;
ptr2 = &num2;
ptr3 = &num3;

if (*ptr1 >= *ptr2 && *ptr1 >= *ptr3)
{
    printf("Greatest number = %d", *ptr1);
}
```

## 📤 Sample Output
```text
Enter first number: 25
Enter second number: 70
Enter third number: 45
Greatest number = 70
```

## 🧠 Concepts Used
- Pointers
- Pointer declaration
- Address-of operator (&)
- Dereference operator (*)
- If-else ladder
- Relational operators
- Logical AND operator

## ⏱️ Time Complexity
O(1)

## 💾 Space Complexity
O(1)

## 📚 Learning Outcome
After completing this program, you will understand how pointers can be used to compare values stored in different variables.

---
**Category:** Pointers  
**Language:** C
