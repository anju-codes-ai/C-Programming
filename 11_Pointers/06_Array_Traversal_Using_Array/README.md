
# 06. Array Traversal Using Pointers

## 📌 Description
This C program traverses an array using pointers.

It accepts five integer elements from the user and displays them using pointer arithmetic instead of directly accessing array elements.

## 🎯 Objective
- Understand the relationship between arrays and pointers.
- Learn array traversal using pointers.
- Practice pointer arithmetic.
- Access array elements using dereferencing.

## 💻 Example
Array:

10, 20, 30, 40, 50

Output:

10 20 30 40 50

## ⚙️ How It Works
1. The program declares an integer array of size five.
2. The user enters five elements.
3. A pointer stores the address of the first array element.
4. A loop traverses the array.
5. `*(ptr + i)` accesses each element.
6. All array elements are displayed.

## 🔑 Pointer Logic
```c
ptr = arr;

for (i = 0; i < 5; i++)
{
    printf("%d ", *(ptr + i));
}
```

## 📤 Sample Output
```text
Enter 5 array elements:
10
20
30
40
50

Array elements using pointers:
10 20 30 40 50
```

## 🧠 Concepts Used
- Pointers
- Arrays
- Array traversal
- Pointer arithmetic
- Dereference operator (*)
- For loop

## ⏱️ Time Complexity
O(n), where n is the number of array elements.

## 💾 Space Complexity
O(1) auxiliary space, excluding the input array.

## 📚 Learning Outcome
After completing this program, you will understand how pointers can be used to access and traverse array elements.

## ⚠️ Important Note
- Array indexing starts from 0.
- `ptr = arr` stores the address of the first element.
- `*(ptr + i)` accesses the element at index i.

---
**Category:** Pointers  
**Language:** C
