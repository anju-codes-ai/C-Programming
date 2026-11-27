
# 08 - Prime Number Using Function

## 📌 Description
This C program checks whether a given integer is
a prime number using a user-defined function.

A prime number is a number greater than 1 that
has exactly two factors: 1 and itself.

The function `checkPrime()` checks whether the
number is divisible by any integer from 2 up to
its square root. It returns 1 if the number is
prime and 0 otherwise.

## 🎯 Objective
- Understand functions with arguments and return values.
- Learn how to check prime numbers.
- Practise loops and conditional statements.
- Understand how functions can return status values.

## 💻 Function Syntax

```c
int checkPrime(int num)
{
    if (num <= 1)
    {
        return 0;
    }

    for (int i = 2; i <= num / i; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }

    return 1;
}
```

## ⚙️ How It Works
1. The program starts execution from `main()`.
2. The user enters an integer.
3. The function `checkPrime()` is called.
4. Numbers less than or equal to 1 are not prime.
5. A loop checks possible divisors starting from 2.
6. If a divisor is found, the function returns 0.
7. If no divisor is found, the function returns 1.
8. The result is displayed using if-else.

## 📤 Sample Output

```text
Enter a number: 17
17 is a Prime number.
```

## 🧠 Concepts Used
- User-defined functions
- Function arguments and parameters
- Integer return type
- Return statement
- For loop
- If-else statement
- Modulus operator (%)

## 📊 Function Characteristics

| Property | Description |
|---|---|
| Function Name | checkPrime |
| Arguments | One integer |
| Return Type | int |
| Return Value | 1 for prime, 0 for not prime |
| Logic | Divisibility checking |

## ⏱️ Time Complexity
O(√n) - Square-root time complexity.

## 📚 Learning Outcome
After completing this program, you will understand
how to use a function to check prime numbers and
return a result using integer values.

## ⚠️ Important Note
- 0 and 1 are not prime numbers.
- Negative numbers are not prime.
- 2 is the smallest prime number.

---
**Part of:** C Programming Practice Repository  
**Category:** Functions  
**Program:** 08
