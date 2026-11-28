
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define DATA_FILE "contacts.dat"
#define TEMP_FILE "temp_contacts.dat"

struct Contact {
    char name[50];
    char phone[20];
    char email[60];
};

/* Read a line of text */
void readLine(const char *message, char *buffer, int size) {
    printf("%s", message);

    if (fgets(buffer, size, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
    } else {
        buffer[0] = '\0';
    }
}

/* Validate phone number */
int validPhone(const char *phone) {
    int length = strlen(phone);

    if (length < 7 || length > 15) {
        return 0;
    }

    for (int i = 0; i < length; i++) {
        if (!isdigit((unsigned char)phone[i])) {
            return 0;
        }
    }

    return 1;
}

/* Read a valid phone number */
void readPhone(const char *message, char *phone, int size) {
    while (1) {
        readLine(message, phone, size);

        if (validPhone(phone)) {
            return;
        }

        printf("Enter a valid phone number (7-15 digits).\n");
    }
}

/* Read a menu choice */
int readChoice(void) {
    char input[100];
    char *end;
    long value;

    while (1) {
        readLine("Enter your choice: ", input, sizeof(input));

        errno = 0;
        value = strtol(input, &end, 10);

        if (input[0] != '\0' && end != input &&
            *end == '\0' && errno == 0 &&
            value >= 1 && value <= 6) {
            return (int)value;
        }

        printf("Enter a choice between 1 and 6.\n");
    }
}

/* Check whether phone number already exists */
int phoneExists(const char *phone) {
    FILE *fp = fopen(DATA_FILE, "rb");
    struct Contact c;

    if (fp == NULL) {
        return 0;
    }

    while (fread(&c, sizeof(c), 1, fp) == 1) {
        if (strcmp(c.phone, phone) == 0) {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

/* Add a new contact */
void addContact(void) {
    FILE *fp;
    struct Contact c;

    readLine("Enter Name: ", c.name, sizeof(c.name));

    if (c.name[0] == '\0') {
        printf("Name cannot be empty.\n");
        return;
    }

    readPhone("Enter Phone Number: ", c.phone, sizeof(c.phone));

    if (phoneExists(c.phone)) {
        printf("This phone number already exists.\n");
        return;
    }

    readLine("Enter Email: ", c.email, sizeof(c.email));

    if (c.email[0] == '\0') {
        printf("Email cannot be empty.\n");
        return;
    }

    fp = fopen(DATA_FILE, "ab");

    if (fp == NULL) {
        printf("Unable to open contact file.\n");
        return;
    }

    if (fwrite(&c, sizeof(c), 1, fp) == 1) {
        printf("Contact added successfully!\n");
    } else {
        printf("Error saving contact.\n");
    }

    fclose(fp);
}

/* Display all contacts */
void displayContacts(void) {
    FILE *fp = fopen(DATA_FILE, "rb");
    struct Contact c;
    int found = 0;

    if (fp == NULL) {
        printf("No contacts found.\n");
        return;
    }

    printf("\n===== CONTACT LIST =====\n");

    while (fread(&c, sizeof(c), 1, fp) == 1) {
        printf("\nName: %s\n", c.name);
        printf("Phone: %s\n", c.phone);
        printf("Email: %s\n", c.email);
        found = 1;
    }

    if (!found) {
        printf("No contacts available.\n");
    }

    if (ferror(fp)) {
        printf("Error reading contact file.\n");
    }

    fclose(fp);
}

/* Search contact by phone number */
void searchContact(void) {
    FILE *fp = fopen(DATA_FILE, "rb");
    struct Contact c;
    char phone[20];
    int found = 0;

    if (fp == NULL) {
        printf("No contacts found.\n");
        return;
    }

    readPhone("Enter phone number to search: ",
              phone, sizeof(phone));

    while (fread(&c, sizeof(c), 1, fp) == 1) {
        if (strcmp(c.phone, phone) == 0) {
            printf("\nContact Found!\n");
            printf("Name: %s\n", c.name);
            printf("Phone: %s\n", c.phone);
            printf("Email: %s\n", c.email);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }

    fclose(fp);
}

/* Update contact details */
void updateContact(void) {
    FILE *fp = fopen(DATA_FILE, "rb");
    FILE *temp;
    struct Contact c;
    char phone[20];
    int found = 0, success = 1;

    if (fp == NULL) {
        printf("No contacts found.\n");
        return;
    }

    readPhone("Enter phone number to update: ",
              phone, sizeof(phone));

    temp = fopen(TEMP_FILE, "wb");

    if (temp == NULL) {
        printf("Unable to create temporary file.\n");
        fclose(fp);
        return;
    }

    while (fread(&c, sizeof(c), 1, fp) == 1) {
        if (strcmp(c.phone, phone) == 0) {
            found = 1;

            printf("Enter new contact details:\n");

            readLine("New Name: ", c.name, sizeof(c.name));
            readPhone("New Phone: ", c.phone, sizeof(c.phone));
            readLine("New Email: ", c.email, sizeof(c.email));

            if (c.name[0] == '\0' || c.email[0] == '\0') {
                printf("Name and email cannot be empty.\n");
                success = 0;
                break;
            }
        }

        if (fwrite(&c, sizeof(c), 1, temp) != 1) {
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
        printf("Update failed. Original file was kept.\n");
        remove(TEMP_FILE);
        return;
    }

    if (!found) {
        printf("Contact not found.\n");
        remove(TEMP_FILE);
        return;
    }

    if (remove(DATA_FILE) != 0) {
        printf("Could not replace contact file.\n");
        remove(TEMP_FILE);
        return;
    }

    if (rename(TEMP_FILE, DATA_FILE) != 0) {
        printf("Could not rename temporary file.\n");
        return;
    }

    printf("Contact updated successfully!\n");
}

/* Delete a contact */
void deleteContact(void) {
    FILE *fp = fopen(DATA_FILE, "rb");
    FILE *temp;
    struct Contact c;
    char phone[20];
    int found = 0, success = 1;

    if (fp == NULL) {
        printf("No contacts found.\n");
        return;
    }

    readPhone("Enter phone number to delete: ",
              phone, sizeof(phone));

    temp = fopen(TEMP_FILE, "wb");

    if (temp == NULL) {
        printf("Unable to create temporary file.\n");
        fclose(fp);
        return;
    }

    while (fread(&c, sizeof(c), 1, fp) == 1) {
        if (strcmp(c.phone, phone) == 0) {
            found = 1;
            continue;
        }

        if (fwrite(&c, sizeof(c), 1, temp) != 1) {
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
        printf("Delete failed. Original file was kept.\n");
        remove(TEMP_FILE);
        return;
    }

    if (!found) {
        printf("Contact not found.\n");
        remove(TEMP_FILE);
        return;
    }

    if (remove(DATA_FILE) != 0) {
        printf("Could not replace contact file.\n");
        remove(TEMP_FILE);
        return;
    }

    if (rename(TEMP_FILE, DATA_FILE) != 0) {
        printf("Could not rename temporary file.\n");
        return;
    }

    printf("Contact deleted successfully!\n");
}

/* Main menu */
int main(void) {
    int choice;

    while (1) {
        printf("\n===== CONTACT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Update Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");

        choice = readChoice();

        switch (choice) {
            case 1:
                addContact();
                break;

            case 2:
                displayContacts();
                break;

            case 3:
                searchContact();
                break;

            case 4:
                updateContact();
                break;

            case 5:
                deleteContact();
                break;

            case 6:
                printf("Thank you for using Contact Management System!\n");
                return 0;
        }
    }
}
