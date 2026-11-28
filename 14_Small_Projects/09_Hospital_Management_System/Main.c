
#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "patients.dat"
#define TEMP_FILE "temp.dat"

struct Patient {
    int id;
    char name[50];
    int age;
    char disease[50];
    double consultationFee;
};

int patientExists(int id) {
    struct Patient p;
    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL)
        return 0;

    while (fread(&p, sizeof(p), 1, fp) == 1) {
        if (p.id == id) {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

void addPatient(void) {
    struct Patient p;

    printf("\nEnter Patient ID: ");
    scanf("%d", &p.id);

    if (p.id <= 0 || patientExists(p.id)) {
        printf("Invalid or duplicate patient ID!\n");
        return;
    }

    printf("Enter Patient Name: ");
    scanf(" %49[^\n]", p.name);

    printf("Enter Age: ");
    scanf("%d", &p.age);

    if (p.age <= 0 || p.age > 120) {
        printf("Invalid age!\n");
        return;
    }

    printf("Enter Disease/Reason for Visit: ");
    scanf(" %49[^\n]", p.disease);

    printf("Enter Consultation Fee: ");
    scanf("%lf", &p.consultationFee);

    if (p.consultationFee < 0) {
        printf("Invalid consultation fee!\n");
        return;
    }

    FILE *fp = fopen(FILE_NAME, "ab");

    if (fp == NULL) {
        printf("Unable to open file!\n");
        return;
    }

    if (fwrite(&p, sizeof(p), 1, fp) == 1) {
        printf("\nPatient record added successfully!\n");
    } else {
        printf("Unable to save patient record.\n");
    }

    fclose(fp);
}

void displayPatients(void) {
    struct Patient p;

    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL) {
        printf("\nNo patient records found.\n");
        return;
    }

    printf("\n========== PATIENT RECORDS ==========\n");

    while (fread(&p, sizeof(p), 1, fp) == 1) {
        printf("\nPatient ID: %d\n", p.id);
        printf("Name: %s\n", p.name);
        printf("Age: %d\n", p.age);
        printf("Disease/Reason: %s\n", p.disease);
        printf("Consultation Fee: Rs. %.2f\n",
               p.consultationFee);
    }

    fclose(fp);
}

void searchPatient(void) {
    struct Patient p;
    int id, found = 0;

    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL) {
        printf("No records available.\n");
        return;
    }

    printf("\nEnter Patient ID: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(p), 1, fp) == 1) {
        if (p.id == id) {
            printf("\nPatient Found!\n");
            printf("ID: %d\n", p.id);
            printf("Name: %s\n", p.name);
            printf("Age: %d\n", p.age);
            printf("Disease/Reason: %s\n", p.disease);
            printf("Fee: Rs. %.2f\n", p.consultationFee);

            found = 1;
            break;
        }
    }

    if (!found)
        printf("Patient not found!\n");

    fclose(fp);
}

void updatePatient(void) {
    struct Patient p;
    int id, found = 0;

    FILE *fp = fopen(FILE_NAME, "rb+");

    if (fp == NULL) {
        printf("No records available.\n");
        return;
    }

    printf("\nEnter Patient ID to update: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(p), 1, fp) == 1) {
        if (p.id == id) {
            printf("Enter New Name: ");
            scanf(" %49[^\n]", p.name);

            printf("Enter New Age: ");
            scanf("%d", &p.age);

            if (p.age <= 0 || p.age > 120) {
                printf("Invalid age!\n");
                fclose(fp);
                return;
            }

            printf("Enter New Disease/Reason: ");
            scanf(" %49[^\n]", p.disease);

            printf("Enter New Consultation Fee: ");
            scanf("%lf", &p.consultationFee);

            if (p.consultationFee < 0) {
                printf("Invalid fee!\n");
                fclose(fp);
                return;
            }

            fseek(fp, -(long)sizeof(p), SEEK_CUR);

            if (fwrite(&p, sizeof(p), 1, fp) == 1)
                printf("Patient record updated!\n");
            else
                printf("Unable to update record.\n");

            found = 1;
            break;
        }
    }

    if (!found)
        printf("Patient not found!\n");

    fclose(fp);
}

void deletePatient(void) {
    struct Patient p;
    int id, found = 0;

    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL) {
        printf("No records available.\n");
        return;
    }

    FILE *temp = fopen(TEMP_FILE, "wb");

    if (temp == NULL) {
        printf("Unable to create temporary file.\n");
        fclose(fp);
        return;
    }

    printf("\nEnter Patient ID to delete: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(p), 1, fp) == 1) {
        if (p.id == id) {
            found = 1;
            continue;
        }

        if (fwrite(&p, sizeof(p), 1, temp) != 1) {
            printf("Error writing temporary file.\n");
            fclose(fp);
            fclose(temp);
            remove(TEMP_FILE);
            return;
        }
    }

    fclose(fp);

    if (fclose(temp) != 0) {
        printf("Error closing temporary file.\n");
        remove(TEMP_FILE);
        return;
    }

    if (!found) {
        remove(TEMP_FILE);
        printf("Patient not found!\n");
        return;
    }

    if (remove(FILE_NAME) != 0) {
        printf("Could not replace original file.\n");
        return;
    }

    if (rename(TEMP_FILE, FILE_NAME) != 0) {
        printf("Replacement failed. Recovery file: temp.dat\n");
        return;
    }

    printf("Patient record deleted successfully!\n");
}

int main(void) {
    int choice;

    do {
        printf("\n================================\n");
        printf("     HOSPITAL MANAGEMENT SYSTEM\n");
        printf("================================\n");
        printf("1. Add Patient\n");
        printf("2. Display Patients\n");
        printf("3. Search Patient\n");
        printf("4. Update Patient\n");
        printf("5. Delete Patient\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient();
                break;

            case 2:
                displayPatients();
                break;

            case 3:
                searchPatient();
                break;

            case 4:
                updatePatient();
                break;

            case 5:
                deletePatient();
                break;

            case 6:
                printf("\nExiting Hospital Management System.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 6);

    return 0;
}
