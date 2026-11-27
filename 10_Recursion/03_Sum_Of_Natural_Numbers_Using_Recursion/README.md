
# 03 - Sum of Natural Numbers Using Recursion in C

## 📌 Description
This C program calculates the sum of the first n
natural numbers using a recursive function.

Recursion allows a function to call itself with
a smaller value until it reaches the base case.

Example:
1 + 2 + 3 + 4 + 5 = 15

The function `sumNatural()` adds the current number
to the result returned by the next recursive call.

## 🎯 Objective
- Understand recursion in C.
- Learn how to calculate a sum recursively.
- Understand base and recursive cases.
- Practise function calls and return statements.

## 💻 Function Syntax

```c
int sumNatural(int num)
{
    if (num == 1)
    {
        return 1;
    }

    return num + sumNatural(num - 1);
}
```

## ⚙️ How It Works
1. The program starts execution from `main()`.
2. The user enters a positive integer.
3. The function `sumNatural()` is called.
4. If the number is 1, the function returns 1.
5. Otherwise, it adds the current number to
   `sumNatural(num - 1)`.
6. The recursive calls continue until the base case.
7. The final sum is returned to `main()`.
8. The result is displayed on the screen.

## 🔁 Recursion Flow

For input 5:

```text
sumNatural(5)
= 5 + sumNatural(4)
= 5 + 4 + sumNatural(3)
= 5 + 4 + 3 + sumNatural(2)
= 5 + 4 + 3 + 2 + sumNatural(1)
= 5 + 4 + 3 + 2 + 1
= 15
```

## 📤 Sample Output

```text
Enter a number: 5
Sum of first 5 natural numbers = 15
```

## 🧠 Concepts Used
- Recursion
- User-defined functions
- Base case
- Recursive case
- Function calling
- Return statement
- If statement

## 📊 Function Characteristics

| Property | Description |
|---|---|
| Function Name | sumNatural |
| Arguments | One integer |
| Return Type | int |
| Base Case | num == 1 |
| Recursive Call | sumNatural(num - 1) |

## ⏱️ Complexity Analysis
- Time Complexity: O(n)
- Auxiliary Space Complexity: O(n) due to recursive calls.

## 📚 Learning Outcome
After completing this program, you will understand
how to calculate the sum of natural numbers through
recursive function calls.

## ⚠️ Important Notes
- Natural numbers start from 1.
- This program expects a positive integer.
- The result must fit within the range of int.

---
**Part of:** C Programming Practice Repository  
**Category:** Recursion  
**Program:** 03
