
#include <stdio.h>

// Function declaration
int isPalindrome(int num);

int main()
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    // Function call
    if (isPalindrome(number))
    {
        printf("%d is a Palindrome number.\n", number);
    }
    else
    {
        printf("%d is not a Palindrome number.\n", number);
    }

    return 0;
}

// Function definition
int isPalindrome(int num)
{
    int original = num;
    int reverse = 0;

    if (num < 0)
    {
        return 0;
    }

    while (num > 0)
    {
        int digit = num % 10;
        reverse = reverse * 10 + digit;
        num = num / 10;
    }

    if (original == reverse)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
