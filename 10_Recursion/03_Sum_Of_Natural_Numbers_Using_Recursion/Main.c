
#include <stdio.h>

// Function declaration
int sumNatural(int num);

int main()
{
    int n, result;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 1)
    {
        printf("Please enter a positive integer.\n");
    }
    else
    {
        // Function call
        result = sumNatural(n);

        printf("Sum of first %d natural numbers = %d\n", n, result);
    }

    return 0;
}

// Recursive function
int sumNatural(int num)
{
    // Base case
    if (num == 1)
    {
        return 1;
    }

    // Recursive call
    return num + sumNatural(num - 1);
}
