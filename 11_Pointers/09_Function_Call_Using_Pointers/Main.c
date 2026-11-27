
#include <stdio.h>

void calculate(int *a, int *b)
{
    *a = *a + 10;
    *b = *b + 20;
}

int main()
{
    int num1, num2;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("\nBefore function call:\n");
    printf("First number = %d\n", num1);
    printf("Second number = %d\n", num2);

    calculate(&num1, &num2);

    printf("\nAfter function call:\n");
    printf("First number = %d\n", num1);
    printf("Second number = %d\n", num2);

    return 0;
}
