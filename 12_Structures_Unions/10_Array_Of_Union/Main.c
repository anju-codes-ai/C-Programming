
#include <stdio.h>

#define SIZE 3

union Data
{
    int number;
    float decimal;
};

int main()
{
    union Data values[SIZE];
    int i;

    // Input integer values
    for (i = 0; i < SIZE; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &values[i].number);
    }

    // Display integer values
    printf("\n----- Array of Union Values -----\n");

    for (i = 0; i < SIZE; i++)
    {
        printf("Number %d: %d\n", i + 1, values[i].number);
    }

    return 0;
}
