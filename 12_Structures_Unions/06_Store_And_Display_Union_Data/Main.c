
#include <stdio.h>

union Employee
{
    int employeeID;
    float salary;
    char grade;
};

int main()
{
    union Employee emp;

    printf("Enter employee ID: ");
    scanf("%d", &emp.employeeID);

    printf("\nEmployee ID: %d\n", emp.employeeID);

    printf("\nEnter employee salary: ");
    scanf("%f", &emp.salary);

    printf("Employee Salary: %.2f\n", emp.salary);

    printf("\nEnter employee grade: ");
    scanf(" %c", &emp.grade);

    printf("Employee Grade: %c\n", emp.grade);

    return 0;
}
