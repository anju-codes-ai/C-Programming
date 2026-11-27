
# 10. Pointer to Pointer (Double Pointer)

## 📌 Description
This C program demonstrates the concept of a pointer to pointer, also known as a double pointer.

A double pointer stores the address of another pointer variable.

It provides another level of indirect access to a variable.

## 🎯 Objective
- Understand double pointers in C.
- Learn multiple levels of indirection.
- Understand pointer-to-pointer declaration.
- Access a variable using two levels of dereferencing.

## 💻 Example
Integer variable:

num = 100

Pointer:

ptr = &num

Double pointer:

pptr = &ptr

Value accessed using double pointer:

**pptr = 100

## ⚙️ How It Works
1. An integer variable `num` is initialized with 100.
2. A pointer `ptr` stores the address of `num`.
3. A double pointer `pptr` stores the address of `ptr`.
4. `*ptr` accesses the value of `num`.
5. `**pptr` accesses the value of `num` through two levels of pointers.
6. The values and addresses are displayed.

## 🔑 Pointer Logic
```c
int num = 100;

int *ptr = &num;

int **pptr = &ptr;
```

Accessing the value:

```c
printf("%d", **pptr);
```

## 📤 Sample Output
```text
Value of num = 100
Value using pointer = 100
Value using double pointer = 100
```

## 🧠 Concepts Used
- Pointers
- Double pointers
- Pointer declaration
- Address-of operator (&)
- Dereference operator (*)
- Multiple levels of indirection

## ⏱️ Time Complexity
O(1)

## 💾 Space Complexity
O(1)

## 📚 Learning Outcome
After completing this program, you will understand how a double pointer stores the address of another pointer and how to access the original value using two dereferencing operations.

## ⚠️ Important Note
- `int *ptr` is a pointer to an integer.
- `int **pptr` is a pointer to an integer pointer.
- `*ptr` accesses the integer value.
- `**pptr` accesses the integer value through the double pointer.
- Always initialize pointers before dereferencing them.

---
**Category:** Pointers  
**Language:** C
