
#include <stdio.h>

int main()
{
    int num, temp, digit;
    int found = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num;

    while (temp > 0)
    {
        digit = temp % 10;

        if (digit == 0)
        {
            found = 1;
            break;
        }

        temp = temp / 10;
    }

    if (num > 0 && found == 1)
        printf("%d is a Duck Number.", num);
    else
        printf("%d is not a Duck Number.", num);

    return 0;
}
