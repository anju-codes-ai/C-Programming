
#include <stdio.h>

int main()
{
    int num = 100;

    int *ptr;
    int **pptr;

    ptr = &num;
    pptr = &ptr;

    printf("Value of num = %d\n", num);

    printf("Value using pointer = %d\n", *ptr);

    printf("Value using double pointer = %d\n", **pptr);

    printf("Address of num = %p\n", (void *)&num);

    printf("Address stored in ptr = %p\n", (void *)ptr);

    printf("Address stored in pptr = %p\n", (void *)pptr);

    return 0;
}
