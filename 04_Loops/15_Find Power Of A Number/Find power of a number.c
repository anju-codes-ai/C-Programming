
#include <stdio.h>

int main()
{
    int base, exponent, result = 1, i = 1;

    printf("Enter the base: ");
    scanf("%d", &base);

    printf("Enter the exponent: ");
    scanf("%d", &exponent);

    do
    {
        result = result * base;
        i++;
    } while (i <= exponent);

    printf("Power = %d\n", result);

    return 0;
}
