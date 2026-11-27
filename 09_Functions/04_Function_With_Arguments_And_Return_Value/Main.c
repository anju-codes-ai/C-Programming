
#include <stdio.h>

// Function declaration
int addNumbers(int a, int b);

int main()
{
    int num1, num2, result;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    // Function call with arguments
    result = addNumbers(num1, num2);

    printf("Sum = %d\n", result);

    return 0;
}

// Function definition
int addNumbers(int a, int b)
{
    return a + b;
}
