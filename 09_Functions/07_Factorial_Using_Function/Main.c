
#include <stdio.h>

// Function declaration
long long int factorial(int num);

int main()
{
    int number;
    long long int result;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (number < 0)
    {
        printf("Factorial is not defined for negative numbers.\n");
    }
    else
    {
        // Function call
        result = factorial(number);

        printf("Factorial of %d = %lld\n", number, result);
    }

    return 0;
}

// Function definition
long long int factorial(int num)
{
    long long int fact = 1;

    for (int i = 1; i <= num; i++)
    {
        fact = fact * i;
    }

    return fact;
}
