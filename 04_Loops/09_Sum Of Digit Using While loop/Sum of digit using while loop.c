
#include <stdio.h>

int main() {
    int num = 12345;
    int sum = 0;

    while (num > 0) {
        int digit = num % 10;
        sum = sum + digit;
        num = num / 10;
    }

    printf("Sum of Digits = %d", sum);

    return 0;
}
