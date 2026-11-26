
#include <stdio.h>

int main() {
    int grade = 2;

    switch (grade) {
        case 1:
            printf("Grade A");
            break;

        case 2:
            printf("Grade B");
            break;

        case 3:
            printf("Grade C");
            break;

        case 4:
            printf("Grade D");
            break;

        default:
            printf("Invalid Grade");
    }

    return 0;
}
