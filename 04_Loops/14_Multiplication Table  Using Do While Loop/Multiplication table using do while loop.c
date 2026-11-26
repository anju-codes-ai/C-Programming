
#include <stdio.h>

int main() {
    int num = 5;
    int i = 1;

    do {
        printf("%d x %d = %d\n", num, i, num * i);
        i++;
    } while (i <= 10);

    return 0;
}
