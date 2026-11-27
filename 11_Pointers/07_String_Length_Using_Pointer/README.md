
# 07. String Length Using Pointers

## 📌 Description
This C program calculates the length of a string using pointers.

It traverses the string character by character without using the built-in `strlen()` function.

## 🎯 Objective
- Understand character pointers.
- Learn string traversal using pointers.
- Calculate string length manually.
- Practice pointer increment and dereferencing.

## 💻 Example
Input:
Hello World

Output:
Length of string = 11

## ⚙️ How It Works
1. The program accepts a string using `fgets()`.
2. A character pointer stores the address of the first character.
3. The `while` loop checks each character.
4. The pointer moves to the next character.
5. The length increases for every character.
6. The loop stops at the null character or newline.
7. The final string length is displayed.

## 🔑 Pointer Logic
```c
while (*ptr != '\0' && *ptr != '\n')
{
    length++;
    ptr++;
}
```

## 📤 Sample Output
```text
Enter a string: Hello World
Length of string = 11
```

## 🧠 Concepts Used
- Character pointers
- Strings
- Pointer increment
- Dereference operator (*)
- While loop
- Null character ('\0')
- fgets() function

## ⏱️ Time Complexity
O(n), where n is the number of characters read.

## 💾 Space Complexity
O(1) auxiliary space, excluding the string storage.

## 📚 Learning Outcome
After completing this program, you will understand how pointers can traverse strings and calculate their length without using a library function.

## ⚠️ Important Note
- `fgets()` safely limits the input to the size of the character array.
- The newline character is excluded from the calculated length.
- The null character (`'\0'`) marks the end of a C string.
- This program does not use `strlen()`.

---
**Category:** Pointers  
**Language:** C
