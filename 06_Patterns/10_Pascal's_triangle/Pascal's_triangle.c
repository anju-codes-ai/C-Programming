
#include <stdio.h>

int main()
{
    int i, j, space;
    int n = 5;

    for (i = 0; i < n; i++)
    {
        // Print spaces
        for (space = 1; space <= n - i; space++)
        {
            printf(" ");
        }

        int value = 1;

        // Print numbers
        for (j = 0; j <= i; j++)
        {
            printf("%d ", value);

            value = value * (i - j) / (j + 1);
        }

        printf("\n");
    }

    return 0;
}
