
#include <stdio.h>

int main() {
    int num = 5;
    int factorial = 1;

    for (int i = 1; i <= num; i++) {
        factorial = factorial * i;
    }

    printf("Factorial of %d = %d", num, factorial);

    return 0;
}
