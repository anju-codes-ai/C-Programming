
#include <stdio.h>

int main()
{
    int num, temp, digit, sum;

    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num;

    while (temp != 1 && temp != 4)
    {
        sum = 0;

        while (temp > 0)
        {
            digit = temp % 10;
            sum = sum + (digit * digit);
            temp = temp / 10;
        }

        temp = sum;
    }

    if (temp == 1)
        printf("%d is a Happy Number.", num);
    else
        printf("%d is not a Happy Number.", num);

    return 0;
}
