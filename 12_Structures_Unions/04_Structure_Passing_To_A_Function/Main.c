
#include <stdio.h>

struct Student
{
    int rollNumber;
    char name[50];
    float marks;
};

void displayStudent(struct Student s)
{
    printf("\n----- Student Details -----\n");

    printf("Roll Number: %d\n", s.rollNumber);
    printf("Name: %s\n", s.name);
    printf("Marks: %.2f\n", s.marks);
}

int main()
{
    struct Student s1;

    printf("Enter roll number: ");
    scanf("%d", &s1.rollNumber);

    printf("Enter student name: ");
    scanf(" %49[^\n]", s1.name);

    printf("Enter marks: ");
    scanf("%f", &s1.marks);

    displayStudent(s1);

    return 0;
}
