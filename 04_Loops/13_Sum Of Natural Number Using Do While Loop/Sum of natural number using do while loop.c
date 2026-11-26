
#include <stdio.h>

int main() {
    int n = 10;
    int i = 1;
    int sum = 0;

    do {
        sum = sum + i;
        i++;
    } while (i <= n);

    printf("Sum = %d", sum);

    return 0;
}
