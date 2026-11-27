
#include <stdio.h>

int main()
{
    int num1, num2, num3;
    int *ptr1, *ptr2, *ptr3;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("Enter third number: ");
    scanf("%d", &num3);

    ptr1 = &num1;
    ptr2 = &num2;
    ptr3 = &num3;

    if (*ptr1 >= *ptr2 && *ptr1 >= *ptr3)
    {
        printf("Greatest number = %d\n", *ptr1);
    }
    else if (*ptr2 >= *ptr1 && *ptr2 >= *ptr3)
    {
        printf("Greatest number = %d\n", *ptr2);
    }
    else
    {
        printf("Greatest number = %d\n", *ptr3);
    }

    return 0;
}
