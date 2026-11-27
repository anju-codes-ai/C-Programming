
#include <stdio.h>

struct Address
{
    char city[50];
    int pinCode;
};

struct Student
{
    int rollNumber;
    char name[50];
    float marks;
    struct Address address;
};

int main()
{
    struct Student s1;

    printf("Enter roll number: ");
    scanf("%d", &s1.rollNumber);

    printf("Enter student name: ");
    scanf(" %49[^\n]", s1.name);

    printf("Enter marks: ");
    scanf("%f", &s1.marks);

    printf("Enter city: ");
    scanf(" %49[^\n]", s1.address.city);

    printf("Enter PIN code: ");
    scanf("%d", &s1.address.pinCode);

    printf("\n----- Student Details -----\n");

    printf("Roll Number: %d\n", s1.rollNumber);
    printf("Name: %s\n", s1.name);
    printf("Marks: %.2f\n", s1.marks);
    printf("City: %s\n", s1.address.city);
    printf("PIN Code: %d\n", s1.address.pinCode);

    return 0;
}
