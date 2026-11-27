
#include <stdio.h>

union Student
{
    int rollNumber;
    float marks;
    char grade;
};

int main()
{
    union Student s;

    s.rollNumber = 101;

    printf("Roll Number: %d\n", s.rollNumber);

    s.marks = 92.5;

    printf("\nMarks: %.2f\n", s.marks);

    s.grade = 'A';

    printf("\nGrade: %c\n", s.grade);

    return 0;
}
