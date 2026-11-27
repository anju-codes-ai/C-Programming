
#include <stdio.h>

// Function declaration
long long int factorial(int num);

int main()
{
    int number;
    long long int result;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (number < 0 || number > 20)
    {
        printf("Please enter a number between 0 and 20.\n");
    }
    else
    {
        result = factorial(number);

        printf("Factorial of %d = %lld\n", number, result);
    }

    return 0;
}

// Recursive function
long long int factorial(int num)
{
    // Base case
    if (num == 0 || num == 1)
    {
        return 1;
    }

    // Recursive call
    return num * factorial(num - 1);
}
