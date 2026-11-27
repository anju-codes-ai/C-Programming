
#include <stdio.h>

// Function declaration
int findGreatest(int a, int b);

int main()
{
    int num1, num2, greatest;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    // Function call
    greatest = findGreatest(num1, num2);

    printf("Greatest number = %d\n", greatest);

    return 0;
}

// Function definition
int findGreatest(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else if (b > a)
    {
        return b;
    }
    else
    {
        return a;
    }
}
