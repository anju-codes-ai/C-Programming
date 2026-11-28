
#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "employees.dat"

struct Employee {
    int id;
    char name[50];
    char department[40];
    double salary;
};

void addEmployee(void) {
    struct Employee emp;

    FILE *fp = fopen(FILE_NAME, "ab");

    if (fp == NULL) {
        printf("Unable to open file!\n");
        return;
    }

    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);

    printf("Enter Employee Name: ");
    scanf(" %49[^\n]", emp.name);

    printf("Enter Department: ");
    scanf(" %39[^\n]", emp.department);

    printf("Enter Monthly Salary: ");
    scanf("%lf", &emp.salary);

    if (emp.id <= 0 || emp.salary < 0) {
        printf("Invalid employee details!\n");
        fclose(fp);
        return;
    }

    fwrite(&emp, sizeof(emp), 1, fp);
    fclose(fp);

    printf("\nEmployee added successfully!\n");
}

void displayEmployees(void) {
    struct Employee emp;

    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL) {
        printf("\nNo employee records found.\n");
        return;
    }

    printf("\n========== EMPLOYEE RECORDS ==========\n");

    while (fread(&emp, sizeof(emp), 1, fp) == 1) {
        printf("\nEmployee ID: %d\n", emp.id);
        printf("Name: %s\n", emp.name);
        printf("Department: %s\n", emp.department);
        printf("Monthly Salary: Rs. %.2f\n", emp.salary);
        printf("Annual Salary: Rs. %.2f\n", emp.salary * 12);
    }

    fclose(fp);
}

void searchEmployee(void) {
    struct Employee emp;
    int searchID, found = 0;

    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL) {
        printf("No records available.\n");
        return;
    }

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchID);

    while (fread(&emp, sizeof(emp), 1, fp) == 1) {
        if (emp.id == searchID) {
            printf("\nEmployee Found!\n");
            printf("ID: %d\n", emp.id);
            printf("Name: %s\n", emp.name);
            printf("Department: %s\n", emp.department);
            printf("Monthly Salary: Rs. %.2f\n", emp.salary);
            printf("Annual Salary: Rs. %.2f\n", emp.salary * 12);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee not found!\n");
    }

    fclose(fp);
}

void updateEmployee(void) {
    struct Employee emp;
    int searchID, found = 0;

    FILE *fp = fopen(FILE_NAME, "rb+");

    if (fp == NULL) {
        printf("No records available.\n");
        return;
    }

    printf("\nEnter Employee ID to update: ");
    scanf("%d", &searchID);

    while (fread(&emp, sizeof(emp), 1, fp) == 1) {
        if (emp.id == searchID) {
            printf("Enter New Name: ");
            scanf(" %49[^\n]", emp.name);

            printf("Enter New Department: ");
            scanf(" %39[^\n]", emp.department);

            printf("Enter New Monthly Salary: ");
            scanf("%lf", &emp.salary);

            if (emp.salary < 0) {
                printf("Invalid salary!\n");
                fclose(fp);
                return;
            }

            fseek(fp, -(long)sizeof(emp), SEEK_CUR);

            if (fwrite(&emp, sizeof(emp), 1, fp) == 1) {
                printf("Employee updated successfully!\n");
            } else {
                printf("Unable to update employee.\n");
            }

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee not found!\n");
    }

    fclose(fp);
}

void deleteEmployee(void) {
    struct Employee emp;
    int deleteID, found = 0;

    FILE *fp = fopen(FILE_NAME, "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (fp == NULL) {
        printf("No records available.\n");

        if (temp != NULL)
            fclose(temp);

        return;
    }

    if (temp == NULL) {
        printf("Unable to create temporary file.\n");
        fclose(fp);
        return;
    }

    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &deleteID);

    while (fread(&emp, sizeof(emp), 1, fp) == 1) {
        if (emp.id == deleteID) {
            found = 1;
            continue;
        }

        fwrite(&emp, sizeof(emp), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    if (found) {
        if (remove(FILE_NAME) != 0 ||
            rename("temp.dat", FILE_NAME) != 0) {
            printf("File replacement failed. Check temp.dat.\n");
        } else {
            printf("Employee deleted successfully!\n");
        }
    } else {
        remove("temp.dat");
        printf("Employee not found!\n");
    }
}

int main(void) {
    int choice;

    do {
        printf("\n================================\n");
        printf("    EMPLOYEE MANAGEMENT SYSTEM\n");
        printf("================================\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;

            case 2:
                displayEmployees();
                break;

            case 3:
                searchEmployee();
                break;

            case 4:
                updateEmployee();
                break;

            case 5:
                deleteEmployee();
                break;

            case 6:
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 6);

    return 0;
}
