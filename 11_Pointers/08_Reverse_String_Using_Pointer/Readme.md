
# 08. Reverse a String Using Pointers

## 📌 Description
This C program reverses a string using pointers.

It uses two pointers: one starting from the beginning of the string and another starting from the end.

The characters are swapped until both pointers meet.

## 🎯 Objective
- Understand character pointers.
- Learn pointer-based string manipulation.
- Practice pointer increment and decrement.
- Reverse a string without using a separate reverse function.

## 💻 Example
Input:
HELLO

Output:
OLLEH

## ⚙️ How It Works
1. The program accepts a string using `fgets()`.
2. The newline character is removed.
3. The `start` pointer points to the first character.
4. The `end` pointer points to the last character.
5. Characters at both positions are swapped.
6. The start pointer moves forward.
7. The end pointer moves backward.
8. The process continues until both pointers meet.
9. The reversed string is displayed.

## 🔑 Pointer Logic
```c
while (start < end)
{
    temp = *start;
    *start = *end;
    *end = temp;

    start++;
    end--;
}
```

## 📤 Sample Output
```text
Enter a string: HELLO
Reversed string = OLLEH
```

## 🧠 Concepts Used
- Character pointers
- Strings
- Pointer increment
- Pointer decrement
- Dereference operator (*)
- String manipulation
- strlen() function
- strcspn() function

## ⏱️ Time Complexity
O(n), where n is the length of the string.

## 💾 Space Complexity
O(1) auxiliary space.

## 📚 Learning Outcome
After completing this program, you will understand how two pointers can be used to reverse a string by swapping characters.

## ⚠️ Important Note
- The program modifies the original string.
- `strlen()` calculates the string length.
- `strcspn()` helps remove the newline character.
- The character array has a maximum capacity of 99 input characters plus the null terminator.

---
**Category:** Pointers  
**Language:** C
