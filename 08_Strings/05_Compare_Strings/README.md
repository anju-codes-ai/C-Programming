
# 05 - Compare Two Strings

## Description
This C program compares two strings using
the strcmp() function and checks whether
both strings are equal or different.

## Concepts Used
- Strings
- Character Arrays
- strcmp() Function
- If-Else Statement
- fgets()
- string.h Header File

## How It Works
1. Declare two character arrays.
2. Read the first string.
3. Read the second string.
4. Remove newline characters from both strings.
5. Compare both strings using strcmp().
6. If the result is zero, both strings are equal.
7. Otherwise, the strings are different.

## Sample Output
```text
Enter first string: Hello
Enter second string: Hello

Both strings are equal.
```

## Learning Outcome
Understand how to compare two strings
using the built-in strcmp() function.

## Function Used
strcmp() - Compares two strings.

Return Value:
0 = Both strings are equal
Negative = First string is smaller
Positive = First string is greater
