
#include <stdio.h>

struct Data
{
    int number;
    float decimal;
    char character;
};

union DataUnion
{
    int number;
    float decimal;
    char character;
};

int main()
{
    struct Data s;
    union DataUnion u;

    printf("Size of Structure: %zu bytes\n", sizeof(s));
    printf("Size of Union: %zu bytes\n", sizeof(u));

    return 0;
}
