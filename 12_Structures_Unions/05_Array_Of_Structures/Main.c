
#include <stdio.h>

#define SIZE 3

struct Student
{
    int rollNumber;
    char name[50];
    float marks;
};

int main()
{
    struct Student students[SIZE];
    int i;

    // Input student details
    for (i = 0; i < SIZE; i++)
    {
        printf("\nEnter details of Student %d\n", i + 1);

        printf("Enter roll number: ");
        scanf("%d", &students[i].rollNumber);

        printf("Enter name: ");
        scanf(" %49[^\n]", students[i].name);

        printf("Enter marks: ");
        scanf("%f", &students[i].marks);
    }

    // Display student details
    printf("\n===== All Student Records =====\n");

    for (i = 0; i < SIZE; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }

    return 0;
}
