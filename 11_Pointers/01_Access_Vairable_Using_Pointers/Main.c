#include <stdio.h>

int main()
{
    int num = 50;

    int *ptr = &num;

    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", (void *)&num);
    printf("Value stored in pointer: %p\n", (void *)ptr);
    printf("Value using pointer: %d\n", *ptr);

    return 0;
}
