
#include <stdio.h>
#include <ctype.h>

int main()
{
    char str[100], upper[100], lower[100];
    int i;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for(i = 0; str[i] != '\0'; i++)
    {
        upper[i] = toupper((unsigned char)str[i]);
        lower[i] = tolower((unsigned char)str[i]);
    }

    upper[i] = '\0';
    lower[i] = '\0';

    printf("Uppercase string: %s", upper);
    printf("Lowercase string: %s", lower);

    return 0;
}
