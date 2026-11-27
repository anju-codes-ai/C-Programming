
#include <stdio.h>
#include <ctype.h>

int main()
{
    char str[200];
    int i, words = 0, inWord = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for(i = 0; str[i] != '\0'; i++)
    {
        if(!isspace((unsigned char)str[i]))
        {
            if(inWord == 0)
            {
                words++;
                inWord = 1;
            }
        }
        else
        {
            inWord = 0;
        }
    }

    printf("Total words = %d", words);

    return 0;
}
