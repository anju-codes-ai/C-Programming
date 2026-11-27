
#include <stdio.h>

// Function declaration
void checkEvenOdd(int num);

int main()
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    // Function call
    checkEvenOdd(number);

    return 0;
}

// Function definition
void checkEvenOdd(int num)
{
    if (num % 2 == 0)
    {
        printf("%d is an Even number.\n", num);
    }
    else
    {
        printf("%d is an Odd number.\n", num);
    }
}
