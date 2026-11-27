
#include <stdio.h>

struct Student
{
    int rollNumber;
    char name[50];
    float marks;
};

int main()
{
    struct Student s1;

    printf("Enter student roll number: ");
    scanf("%d", &s1.rollNumber);

    printf("Enter student name: ");
    scanf(" %49[^\n]", s1.name);

    printf("Enter student marks: ");
    scanf("%f", &s1.marks);

    printf("\n----- Student Details -----\n");

    printf("Roll Number: %d\n", s1.rollNumber);
    printf("Name: %s\n", s1.name);
    printf("Marks: %.2f\n", s1.marks);

    return 0;
}
