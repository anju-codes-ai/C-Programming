
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define DATA_FILE "books.dat"
#define TEMP_FILE "temp_books.dat"

struct Book {
    int id;
    char title[100];
    char author[60];
    int available;
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

/* Read a positive integer */
int readPositiveInt(const char *message) {
    char input[100];
    char *end;
    long value;

    while (1) {
        readLine(message, input, sizeof(input));

        errno = 0;
        value = strtol(input, &end, 10);

        if (input[0] != '\0' && end != input &&
            *end == '\0' && errno == 0 &&
            value > 0 && value <= 1000000000L) {
            return (int)value;
        }

        printf("Enter a valid positive number.\n");
    }
}

/* Check whether book ID exists */
int bookExists(int id) {
    FILE *fp = fopen(DATA_FILE, "rb");
    struct Book b;

    if (fp == NULL) {
        return 0;
    }

    while (fread(&b, sizeof(b), 1, fp) == 1) {
        if (b.id == id) {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

/* Add a new book */
void addBook(void) {
    FILE *fp;
    struct Book b;

    b.id = readPositiveInt("Enter Book ID: ");

    if (bookExists(b.id)) {
        printf("Book ID already exists.\n");
        return;
    }

    readLine("Enter Book Title: ", b.title, sizeof(b.title));
    readLine("Enter Author Name: ", b.author, sizeof(b.author));

    if (b.title[0] == '\0' || b.author[0] == '\0') {
        printf("Title and author cannot be empty.\n");
        return;
    }

    b.available = 1;

    fp = fopen(DATA_FILE, "ab");

    if (fp == NULL) {
        printf("Unable to open book file.\n");
        return;
    }

    if (fwrite(&b, sizeof(b), 1, fp) == 1) {
        printf("Book added successfully!\n");
    } else {
        printf("Error saving book record.\n");
    }

    fclose(fp);
}

/* Display all books */
void displayBooks(void) {
    FILE *fp = fopen(DATA_FILE, "rb");
    struct Book b;
    int found = 0;

    if (fp == NULL) {
        printf("No book records found.\n");
        return;
    }

    printf("\n===== LIBRARY BOOKS =====\n");

    while (fread(&b, sizeof(b), 1, fp) == 1) {
        printf("\nBook ID: %d\n", b.id);
        printf("Title: %s\n", b.title);
        printf("Author: %s\n", b.author);
        printf("Status: %s\n",
               b.available ? "Available" : "Issued");
        found = 1;
    }

    if (!found) {
        printf("No books available.\n");
    }

    if (ferror(fp)) {
        printf("Error reading book records.\n");
    }

    fclose(fp);
}

/* Search a book */
void searchBook(void) {
    FILE *fp = fopen(DATA_FILE, "rb");
    struct Book b;
    int id, found = 0;

    if (fp == NULL) {
        printf("No book records found.\n");
        return;
    }

    id = readPositiveInt("Enter Book ID to search: ");

    while (fread(&b, sizeof(b), 1, fp) == 1) {
        if (b.id == id) {
            printf("\nBook Found!\n");
            printf("Book ID: %d\n", b.id);
            printf("Title: %s\n", b.title);
            printf("Author: %s\n", b.author);
            printf("Status: %s\n",
                   b.available ? "Available" : "Issued");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }

    fclose(fp);
}

/* Issue or return a book */
void changeBookStatus(int issue) {
    FILE *fp = fopen(DATA_FILE, "rb");
    FILE *temp;
    struct Book b;
    int id, found = 0, success = 1;

    if (fp == NULL) {
        printf("No book records found.\n");
        return;
    }

    id = readPositiveInt("Enter Book ID: ");

    temp = fopen(TEMP_FILE, "wb");

    if (temp == NULL) {
        printf("Unable to create temporary file.\n");
        fclose(fp);
        return;
    }

    while (fread(&b, sizeof(b), 1, fp) == 1) {
        if (b.id == id) {
            found = 1;

            if (issue && !b.available) {
                printf("This book is already issued.\n");
                success = 0;
                break;
            }

            if (!issue && b.available) {
                printf("This book is already available.\n");
                success = 0;
                break;
            }

            b.available = issue ? 0 : 1;
        }

        if (fwrite(&b, sizeof(b), 1, temp) != 1) {
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
        printf("Operation could not be completed.\n");
        remove(TEMP_FILE);
        return;
    }

    if (!found) {
        printf("Book not found.\n");
        remove(TEMP_FILE);
        return;
    }

    if (remove(DATA_FILE) != 0) {
        printf("Could not replace the original file.\n");
        remove(TEMP_FILE);
        return;
    }

    if (rename(TEMP_FILE, DATA_FILE) != 0) {
        printf("Could not rename the temporary file.\n");
        return;
    }

    printf("Book %s successfully!\n",
           issue ? "issued" : "returned");
}

/* Main menu */
int main(void) {
    int choice;

    while (1) {
        printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");

        choice = readPositiveInt("Enter your choice: ");

        switch (choice) {
            case 1:
                addBook();
                break;

            case 2:
                displayBooks();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                changeBookStatus(1);
                break;

            case 5:
                changeBookStatus(0);
                break;

            case 6:
                printf("Thank you for using the library system!\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
