
#include <stdio.h>

int main()
{
    int num, temp, digit;
    int sum = 0, product = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num;

    while (temp > 0)
    {
        digit = temp % 10;

        sum = sum + digit;
        product = product * digit;

        temp = temp / 10;
    }

    if (num >= 0 && sum == product)
        printf("%d is a Spy Number.", num);
    else
        printf("%d is not a Spy Number.", num);

    return 0;
}
