
#include <stdio.h>

// Function declaration
int sumOfDigits(int num);

int main()
{
    int number, result;

    printf("Enter a number: ");
    scanf("%d", &number);

    // Function call
    result = sumOfDigits(number);

    printf("Sum of digits = %d\n", result);

    return 0;
}

// Function definition
int sumOfDigits(int num)
{
    int sum = 0;

    if (num < 0)
    {
        num = -num;
    }

    while (num > 0)
    {
        int digit = num % 10;
        sum = sum + digit;
        num = num / 10;
    }

    return sum;
}
