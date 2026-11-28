
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define DATA_FILE "accounts.dat"
#define TEMP_FILE "temp_accounts.dat"

struct Account {
    int accountNumber;
    char name[50];
    double balance;
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

/* Read a positive monetary amount */
double readAmount(const char *message) {
    char input[100];
    char *end;
    double value;

    while (1) {
        readLine(message, input, sizeof(input));

        errno = 0;
        value = strtod(input, &end);

        if (input[0] != '\0' && end != input &&
            *end == '\0' && errno == 0 &&
            value > 0 && value <= 1000000000.0) {
            return value;
        }

        printf("Enter a valid positive amount.\n");
    }
}

/* Check whether an account number already exists */
int accountExists(int number) {
    FILE *fp = fopen(DATA_FILE, "rb");
    struct Account a;

    if (fp == NULL) {
        return 0;
    }

    while (fread(&a, sizeof(a), 1, fp) == 1) {
        if (a.accountNumber == number) {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

/* Create a new account */
void createAccount(void) {
    FILE *fp;
    struct Account a;

    a.accountNumber = readPositiveInt("Enter account number: ");

    if (accountExists(a.accountNumber)) {
        printf("Account number already exists.\n");
        return;
    }

    readLine("Enter account holder name: ", a.name, sizeof(a.name));

    if (a.name[0] == '\0') {
        printf("Name cannot be empty.\n");
        return;
    }

    a.balance = readAmount("Enter initial deposit: ");

    fp = fopen(DATA_FILE, "ab");

    if (fp == NULL) {
        printf("Unable to open account file.\n");
        return;
    }

    if (fwrite(&a, sizeof(a), 1, fp) == 1) {
        printf("Account created successfully!\n");
    } else {
        printf("Error saving account.\n");
    }

    fclose(fp);
}

/* Display all accounts */
void displayAccounts(void) {
    FILE *fp = fopen(DATA_FILE, "rb");
    struct Account a;
    int found = 0;

    if (fp == NULL) {
        printf("No accounts found.\n");
        return;
    }

    printf("\n===== ALL BANK ACCOUNTS =====\n");

    while (fread(&a, sizeof(a), 1, fp) == 1) {
        printf("\nAccount Number: %d\n", a.accountNumber);
        printf("Holder Name: %s\n", a.name);
        printf("Balance: %.2f\n", a.balance);
        found = 1;
    }

    if (!found) {
        printf("No accounts found.\n");
    }

    if (ferror(fp)) {
        printf("Error reading account file.\n");
    }

    fclose(fp);
}

/* Search an account */
void searchAccount(void) {
    FILE *fp = fopen(DATA_FILE, "rb");
    struct Account a;
    int number, found = 0;

    if (fp == NULL) {
        printf("No accounts found.\n");
        return;
    }

    number = readPositiveInt("Enter account number: ");

    while (fread(&a, sizeof(a), 1, fp) == 1) {
        if (a.accountNumber == number) {
            printf("\nAccount Found!\n");
            printf("Account Number: %d\n", a.accountNumber);
            printf("Holder Name: %s\n", a.name);
            printf("Balance: %.2f\n", a.balance);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Account not found.\n");
    }

    fclose(fp);
}

/* Update account balance through a temporary file */
void updateBalance(int number, double amount, int isDeposit) {
    FILE *fp = fopen(DATA_FILE, "rb");
    FILE *temp;
    struct Account a;
    int found = 0, success = 1;

    if (fp == NULL) {
        printf("No accounts found.\n");
        return;
    }

    temp = fopen(TEMP_FILE, "wb");

    if (temp == NULL) {
        printf("Unable to create temporary file.\n");
        fclose(fp);
        return;
    }

    while (fread(&a, sizeof(a), 1, fp) == 1) {
        if (a.accountNumber == number) {
            found = 1;

            if (isDeposit) {
                if (a.balance > 1000000000.0 - amount) {
                    printf("Balance limit exceeded.\n");
                    success = 0;
                    break;
                }
                a.balance += amount;
            } else {
                if (a.balance < amount) {
                    printf("Insufficient balance.\n");
                    success = 0;
                    break;
                }
                a.balance -= amount;
            }
        }

        if (fwrite(&a, sizeof(a), 1, temp) != 1) {
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
        printf("Transaction could not be completed.\n");
        remove(TEMP_FILE);
        return;
    }

    if (!found) {
        printf("Account not found.\n");
        remove(TEMP_FILE);
        return;
    }

    if (remove(DATA_FILE) != 0) {
        printf("Could not replace account file.\n");
        remove(TEMP_FILE);
        return;
    }

    if (rename(TEMP_FILE, DATA_FILE) != 0) {
        printf("Could not rename temporary file.\n");
        return;
    }

    printf("Transaction successful!\n");
}

/* Deposit money */
void depositMoney(void) {
    int number = readPositiveInt("Enter account number: ");
    double amount = readAmount("Enter deposit amount: ");

    updateBalance(number, amount, 1);
}

/* Withdraw money */
void withdrawMoney(void) {
    int number = readPositiveInt("Enter account number: ");
    double amount = readAmount("Enter withdrawal amount: ");

    updateBalance(number, amount, 0);
}

/* Main function */
int main(void) {
    int choice;

    while (1) {
        printf("\n===== BANKING MANAGEMENT SYSTEM =====\n");
        printf("1. Create Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Search Account\n");
        printf("4. Deposit Money\n");
        printf("5. Withdraw Money\n");
        printf("6. Exit\n");

        choice = readPositiveInt("Enter your choice: ");

        switch (choice) {
            case 1:
                createAccount();
                break;

            case 2:
                displayAccounts();
                break;

            case 3:
                searchAccount();
                break;

            case 4:
                depositMoney();
                break;

            case 5:
                withdrawMoney();
                break;

            case 6:
                printf("Thank you for using Banking Management System!\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
