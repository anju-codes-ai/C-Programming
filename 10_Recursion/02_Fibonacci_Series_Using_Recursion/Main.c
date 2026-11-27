
#include <stdio.h>

// Function declaration
int fibonacci(int num);

int main()
{
    int n;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    if (n <= 0 || n > 40)
    {
        printf("Please enter terms between 1 and 40.\n");
    }
    else
    {
        printf("Fibonacci Series: ");

        for (int i = 0; i < n; i++)
        {
            printf("%d ", fibonacci(i));
        }

        printf("\n");
    }

    return 0;
}

// Recursive function
int fibonacci(int num)
{
    // Base cases
    if (num == 0)
    {
        return 0;
    }

    if (num == 1)
    {
        return 1;
    }

    // Recursive calls
    return fibonacci(num - 1) + fibonacci(num - 2);
}
