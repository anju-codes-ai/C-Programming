
#include <stdio.h>

// Function declaration
int checkPrime(int num);

int main()
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    // Function call
    if (checkPrime(number))
    {
        printf("%d is a Prime number.\n", number);
    }
    else
    {
        printf("%d is not a Prime number.\n", number);
    }

    return 0;
}

// Function definition
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
