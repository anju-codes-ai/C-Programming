
#include <stdio.h>

int main() {
    int n = 10;
    int a = 0, b = 1, next;
    int i = 1;

    while (i <= n) {
        printf("%d ", a);

        next = a + b;
        a = b;
        b = next;

        i++;
    }

    return 0;
}
