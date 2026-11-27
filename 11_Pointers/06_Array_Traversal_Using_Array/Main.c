
#include <stdio.h>

int main()
{
    int arr[5];
    int *ptr;
    int i;

    printf("Enter 5 array elements:\n");

    for (i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }

    ptr = arr;

    printf("\nArray elements using pointers:\n");

    for (i = 0; i < 5; i++)
    {
        printf("%d ", *(ptr + i));
    }

    printf("\n");

    return 0;
}
