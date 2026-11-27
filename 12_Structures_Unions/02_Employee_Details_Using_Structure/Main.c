
#include <stdio.h>

struct Employee
{
    int employeeID;
    char name[50];
    float salary;
};

int main()
{
    struct Employee emp;

    printf("Enter employee ID: ");
    scanf("%d", &emp.employeeID);

    printf("Enter employee name: ");
    scanf(" %49[^\n]", emp.name);

    printf("Enter employee salary: ");
    scanf("%f", &emp.salary);

    printf("\n----- Employee Details -----\n");

    printf("Employee ID: %d\n", emp.employeeID);
    printf("Employee Name: %s\n", emp.name);
    printf("Salary: %.2f\n", emp.salary);

    return 0;
}
