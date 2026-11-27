
#include <stdio.h>

// Function declaration
void addNumbers(int a, int b);

int main()
{
    int num1, num2;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    // Function call with arguments
    addNumbers(num1, num2);

    return 0;
}

// Function definition
void addNumbers(int a, int b)
{
    int sum = a + b;

    printf("Sum = %d\n", sum);
}
