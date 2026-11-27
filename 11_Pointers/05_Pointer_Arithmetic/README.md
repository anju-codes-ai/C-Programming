
# 05. Pointer Arithmetic in C

## 📌 Description
This C program demonstrates pointer arithmetic using an integer array.

Pointer arithmetic allows us to move through array elements by incrementing, decrementing, or adding an integer value to a pointer.

## 🎯 Objective
- Understand pointer arithmetic.
- Learn pointer increment and decrement.
- Access array elements using pointers.
- Understand the relationship between arrays and pointers.

## 💻 Example
Array:

10, 20, 30, 40, 50

Initially, the pointer points to 10.

After incrementing, it points to 20.

After decrementing, it points back to 10.

## ⚙️ How It Works
1. An integer array is initialized with five elements.
2. A pointer stores the address of the first array element.
3. `ptr++` moves the pointer to the next element.
4. `ptr--` moves it to the previous element.
5. `ptr + 2` accesses the third element.
6. The values are displayed using the dereference operator.

## 🔑 Pointer Arithmetic Operations
```c
ptr++;       // Move to next element
ptr--;       // Move to previous element
*(ptr + 2);  // Access element at index 2
*(ptr + 3);  // Access element at index 3
```

## 📤 Sample Output
```text
Pointer Arithmetic Operations:

Original value: 10
After increment: 20
After decrement: 10
Value at ptr + 2: 30
Value at ptr + 3: 40
```

## 🧠 Concepts Used
- Pointers
- Arrays
- Pointer increment
- Pointer decrement
- Pointer addition
- Dereference operator (*)
- Memory addresses

## ⏱️ Time Complexity
O(1) for each pointer operation.

## 💾 Space Complexity
O(1) auxiliary space.

## 📚 Learning Outcome
After completing this program, you will understand how pointers move between array elements and how pointer arithmetic works in C.

## ⚠️ Important Note
- Pointer arithmetic depends on the data type.
- For an integer pointer, incrementing it moves to the next integer element.
- Pointer arithmetic must stay within the same array or one position past its end. Do not dereference a one-past-the-end pointer.

---
**Category:** Pointers  
**Language:** C
