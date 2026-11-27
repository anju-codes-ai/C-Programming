
# 01. Access Variable Using Pointer

## 📌 Description
This C program demonstrates the basic concept of pointers.

A pointer is a variable that stores the memory address of another variable.

The program accesses the value of a normal variable using a pointer.

## 🎯 Objective
- Understand pointers in C.
- Learn how to declare a pointer.
- Learn the address-of operator (&).
- Learn the dereference operator (*).
- Access a variable through its pointer.

## 💻 Example
Integer variable:

num = 50

Pointer:

ptr = address of num

Value accessed using pointer:

*ptr = 50

## ⚙️ How It Works
1. An integer variable `num` is initialized with 50.
2. A pointer `ptr` is declared.
3. The address of `num` is stored inside `ptr`.
4. The program displays the variable's value.
5. The program displays the variable's memory address.
6. The pointer is used to access the original value.

## 🔑 Pointer Syntax

```c
int *ptr;
```

Here:
- `int` represents the data type.
- `*` indicates that ptr is a pointer.
- `ptr` is the pointer variable.

## 📤 Sample Output
```text
Value of num: 50
Address of num: 0x7ffe...
Value stored in pointer: 0x7ffe...
Value using pointer: 50
```

Note: Memory addresses vary between executions.

## 🧠 Concepts Used
- Pointers
- Pointer declaration
- Address-of operator (&)
- Dereference operator (*)
- Memory addresses
- Integer variables

## ⏱️ Time Complexity
O(1)

## 💾 Space Complexity
O(1)

## 📚 Learning Outcome
After completing this program, you will understand how pointers store memory addresses and how they access values stored in memory.

---
**Category:** Pointers  
**Language:** C
```

### GitHub folder structure

```text
08_Pointers/
│
└── 01_Access_Variable_Using_Pointer/
    ├── main.c
    └── README.md
```

**Next → Program 02: Swap Two Numbers Using Pointers** — one of the most important pointer programs for practicals, viva and exams.
