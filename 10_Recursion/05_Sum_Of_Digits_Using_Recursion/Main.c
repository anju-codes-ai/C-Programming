
#include <stdio.h>

int sumOfDigits(int num)
{
    // Base case
    if (num == 0)
    {
        return 0;
    }

    // Recursive call
    return (num % 10) + sumOfDigits(num / 10);
}

int main()
{
    int number, result;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (number < 0)
    {
        printf("Please enter a non-negative number.\n");
    }
    else
    {
        result = sumOfDigits(number);
        printf("Sum of digits = %d\n", result);
    }

    return 0;
}
