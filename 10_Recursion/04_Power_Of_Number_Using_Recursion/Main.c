
#include <stdio.h>

long long int power(int base, int exponent)
{
    // Base case
    if (exponent == 0)
    {
        return 1;
    }

    // Recursive call
    return base * power(base, exponent - 1);
}

int main()
{
    int base, exponent;
    long long int result;

    printf("Enter the base: ");
    scanf("%d", &base);

    printf("Enter the exponent: ");
    scanf("%d", &exponent);

    if (exponent < 0)
    {
        printf("Please enter a non-negative exponent.\n");
    }
    else
    {
        result = power(base, exponent);
        printf("%d raised to power %d = %lld\n",
               base, exponent, result);
    }

    return 0;
}
