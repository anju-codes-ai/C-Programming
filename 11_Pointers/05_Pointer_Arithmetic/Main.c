
#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30, 40, 50};

    int *ptr = arr;

    printf("Pointer Arithmetic Operations:\n\n");

    printf("Original value: %d\n", *ptr);

    printf("After increment: ");
    ptr++;
    printf("%d\n", *ptr);

    printf("After decrement: ");
    ptr--;
    printf("%d\n", *ptr);

    printf("Value at ptr + 2: %d\n", *(ptr + 2));

    printf("Value at ptr + 3: %d\n", *(ptr + 3));

    return 0;
}
