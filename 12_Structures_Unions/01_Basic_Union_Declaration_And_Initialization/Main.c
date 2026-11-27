
#include <stdio.h>

union Data
{
    int number;
    float decimal;
    char character;
};

int main()
{
    union Data d;

    d.number = 100;

    printf("Union Member Values\n");
    printf("Integer Number: %d\n", d.number);

    d.decimal = 25.5;

    printf("\nAfter assigning float value:\n");
    printf("Decimal Number: %.2f\n", d.decimal);

    d.character = 'A';

    printf("\nAfter assigning character value:\n");
    printf("Character: %c\n", d.character);

    return 0;
}
