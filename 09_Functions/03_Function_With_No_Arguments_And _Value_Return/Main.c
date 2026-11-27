
#include <stdio.h>

// Function declaration
int addNumbers(void);

int main()
{
    int result;

    // Function call and receive returned value
    result = addNumbers();

    printf("Sum = %d\n", result);

    return 0;
}

// Function definition
int addNumbers(void)
{
    int a, b;

    printf("Enter first number: ");
    scanf("%d", &a);

    printf("Enter second number: ");
    scanf("%d", &b);

    return a + b;
}
