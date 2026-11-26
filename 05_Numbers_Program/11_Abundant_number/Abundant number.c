
#include <stdio.h>

int main()
{
    int num, i, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    for (i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            sum = sum + i;
        }
    }

    if (num > 0 && sum > num)
        printf("%d is an Abundant Number.", num);
    else
        printf("%d is not an Abundant Number.", num);

    return 0;
}
