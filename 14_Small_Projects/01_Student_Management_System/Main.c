
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define DATA_FILE "students.dat"
#define TEMP_FILE "temp.dat"

struct Student {
    int id;
    char name[50];
    int age;
    char course[50];
};

/* Read a complete line, including spaces */
void readLine(const char *message, char *buffer, int size) {
    printf("%s", message);

    if (fgets(buffer, size, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
    } else {
        buffer[0] = '\0';
    }
}

/* Read and validate an integer */
int readInt(const char *message) {
    char input[100];
    char *end;
    long value;

    while (1) {
        readLine(message, input, sizeof(input));

        errno = 0;
        value = strtol(input, &end, 10);

        if (input[0] != '\0' && *end == '\0' &&
            end != input && errno == 0 &&
            value >= 1 && value <= 1000000) {
            return (int)value;
        }

        printf("Please enter a valid positive number.\n");
    }
}

/* Check whether a student ID already exists */
int idExists(int id) {
    FILE *fp = fopen(DATA_FILE, "rb");
    struct Student s;

    if (fp == NULL) {
        return 0;
    }

    while (fread(&s, sizeof(s), 1, fp) == 1) {
        if (s.id == id) {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

/* Add a new student */
void addStudent(void) {
    FILE *fp;
    struct Student s;

    s.id = readInt("Enter Student ID: ");

    if (idExists(s.id)) {
        printf("This student ID already exists.\n");
        return;
    }

    readLine("Enter Student Name: ", s.name, sizeof(s.name));
    s.age = readInt("Enter Student Age: ");
    readLine("Enter Course Name: ", s.course, sizeof(s.course));

    if (s.name[0] == '\0' || s.course[0] == '\0') {
        printf("Name and course cannot be empty.\n");
        return;
    }

    fp = fopen(DATA_FILE, "ab");

    if (fp == NULL) {
        printf("Unable to open student file.\n");
        return;
    }

    if (fwrite(&s, sizeof(s), 1, fp) == 1) {
        printf("Student record added successfully!\n");
    } else {
        printf("Error saving student record.\n");
    }

    fclose(fp);
}

/* Display all student records */
void displayStudents(void) {
    FILE *fp = fopen(DATA_FILE, "rb");
    struct Student s;
    int found = 0;

    if (fp == NULL) {
        printf("No student records found.\n");
        return;
    }

    printf("\n----- STUDENT RECORDS -----\n");

    while (fread(&s, sizeof(s), 1, fp) == 1) {
        printf("\nID: %d\n", s.id);
        printf("Name: %s\n", s.name);
        printf("Age: %d\n", s.age);
        printf("Course: %s\n", s.course);
        found = 1;
    }

    if (!found) {
        printf("No student records found.\n");
    }

    if (ferror(fp)) {
        printf("Error reading student file.\n");
    }

    fclose(fp);
}

/* Search for a student by ID */
void searchStudent(void) {
    FILE *fp = fopen(DATA_FILE, "rb");
    struct Student s;
    int id, found = 0;

    if (fp == NULL) {
        printf("No student records found.\n");
        return;
    }

    id = readInt("Enter Student ID to search: ");

    while (fread(&s, sizeof(s), 1, fp) == 1) {
        if (s.id == id) {
            printf("\nStudent Found!\n");
            printf("ID: %d\n", s.id);
            printf("Name: %s\n", s.name);
            printf("Age: %d\n", s.age);
            printf("Course: %s\n", s.course);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }

    fclose(fp);
}

/* Replace the original data file with the temporary file */
int replaceDataFile(void) {
    if (remove(DATA_FILE) != 0) {
        printf("Could not replace the original data file.\n");
        remove(TEMP_FILE);
        return 0;
    }

    if (rename(TEMP_FILE, DATA_FILE) != 0) {
        printf("Could not rename the temporary file.\n");
        return 0;
    }

    return 1;
}

/* Update student details */
void updateStudent(void) {
    FILE *fp = fopen(DATA_FILE, "rb");
    FILE *temp;
    struct Student s;
    int id, found = 0, success = 1;

    if (fp == NULL) {
        printf("No student records found.\n");
        return;
    }

    id = readInt("Enter Student ID to update: ");

    temp = fopen(TEMP_FILE, "wb");

    if (temp == NULL) {
        printf("Unable to create temporary file.\n");
        fclose(fp);
        return;
    }

    while (fread(&s, sizeof(s), 1, fp) == 1) {
        if (s.id == id) {
            printf("Enter new details:\n");
            readLine("New Name: ", s.name, sizeof(s.name));
            s.age = readInt("New Age: ");
            readLine("New Course: ", s.course, sizeof(s.course));

            if (s.name[0] == '\0' || s.course[0] == '\0') {
                printf("Name and course cannot be empty.\n");
                success = 0;
                break;
            }

            found = 1;
        }

        if (fwrite(&s, sizeof(s), 1, temp) != 1) {
            success = 0;
            break;
        }
    }

    if (ferror(fp)) {
        success = 0;
    }

    fclose(fp);

    if (fclose(temp) != 0) {
        success = 0;
    }

    if (!success) {
        printf("Error updating records. Original file was kept.\n");
        remove(TEMP_FILE);
        return;
    }

    if (!found) {
        printf("Student not found.\n");
        remove(TEMP_FILE);
        return;
    }

    if (replaceDataFile()) {
        printf("Student record updated successfully!\n");
    }
}

/* Delete a student record */
void deleteStudent(void) {
    FILE *fp = fopen(DATA_FILE, "rb");
    FILE *temp;
    struct Student s;
    int id, found = 0, success = 1;

    if (fp == NULL) {
        printf("No student records found.\n");
        return;
    }

    id = readInt("Enter Student ID to delete: ");

    temp = fopen(TEMP_FILE, "wb");

    if (temp == NULL) {
        printf("Unable to create temporary file.\n");
        fclose(fp);
        return;
    }

    while (fread(&s, sizeof(s), 1, fp) == 1) {
        if (s.id == id) {
            found = 1;
            continue;
        }

        if (fwrite(&s, sizeof(s), 1, temp) != 1) {
            success = 0;
            break;
        }
    }

    if (ferror(fp)) {
        success = 0;
    }

    fclose(fp);

    if (fclose(temp) != 0) {
        success = 0;
    }

    if (!success) {
        printf("Error deleting record. Original file was kept.\n");
        remove(TEMP_FILE);
        return;
    }

    if (!found) {
        printf("Student not found.\n");
        remove(TEMP_FILE);
        return;
    }

    if (replaceDataFile()) {
        printf("Student record deleted successfully!\n");
    }
}

/* Main menu */
int main(void) {
    int choice;

    while (1) {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                printf("Thank you for using the system!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
