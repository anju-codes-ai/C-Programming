
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ACCOUNT_FILE "atm_account.dat"
#define HISTORY_FILE "transaction_history.txt"

struct Account {
    int accountNumber;
    int pin;
    char name[50];
    double balance;
};

int loadAccount(struct Account *account) {
    FILE *fp = fopen(ACCOUNT_FILE, "rb");

    if (fp == NULL)
        return 0;

    int result = fread(account, sizeof(struct Account), 1, fp);
    fclose(fp);

    return result == 1;
}

int saveAccount(struct Account account) {
    FILE *fp = fopen(ACCOUNT_FILE, "wb");

    if (fp == NULL) {
        printf("Error saving account!\n");
        return 0;
    }

    int result = fwrite(&account, sizeof(struct Account), 1, fp);
    fclose(fp);

    return result == 1;
}

void saveTransaction(const char *type, double amount) {
    FILE *fp = fopen(HISTORY_FILE, "a");

    if (fp == NULL) {
        printf("Could not save transaction history.\n");
        return;
    }

    fprintf(fp, "%s: Rs. %.2f\n", type, amount);
    fclose(fp);
}

void createAccount(struct Account *account) {
    printf("\n--- Create ATM Account ---\n");

    printf("Enter account number: ");
    scanf("%d", &account->accountNumber);

    printf("Enter account holder name: ");
    scanf(" %49[^\n]", account->name);

    printf("Set a 4-digit PIN: ");
    scanf("%d", &account->pin);

    if (account->pin < 1000 || account->pin > 9999) {
        printf("Invalid PIN! Use exactly 4 digits.\n");
        return;
    }

    account->balance = 0.0;

    if (saveAccount(*account)) {
        printf("\nAccount created successfully!\n");
    }
}

void checkBalance(struct Account account) {
    printf("\nAvailable Balance: Rs. %.2f\n",
           account.balance);
}

void deposit(struct Account *account) {
    double amount;

    printf("Enter deposit amount: Rs. ");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("Enter a valid positive amount.\n");
        return;
    }

    account->balance += amount;

    if (saveAccount(*account)) {
        saveTransaction("Deposit", amount);
        printf("Deposit successful!\n");
    }
}

void withdraw(struct Account *account) {
    double amount;

    printf("Enter withdrawal amount: Rs. ");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("Enter a valid positive amount.\n");
        return;
    }

    if (amount > account->balance) {
        printf("Insufficient balance!\n");
        return;
    }

    account->balance -= amount;

    if (saveAccount(*account)) {
        saveTransaction("Withdrawal", amount);
        printf("Please collect your cash (simulation).\n");
    }
}

void changePIN(struct Account *account) {
    int oldPIN, newPIN;

    printf("Enter current PIN: ");
    scanf("%d", &oldPIN);

    if (oldPIN != account->pin) {
        printf("Incorrect current PIN!\n");
        return;
    }

    printf("Enter new 4-digit PIN: ");
    scanf("%d", &newPIN);

    if (newPIN < 1000 || newPIN > 9999) {
        printf("Invalid PIN! Use exactly 4 digits.\n");
        return;
    }

    account->pin = newPIN;

    if (saveAccount(*account)) {
        printf("PIN changed successfully!\n");
    }
}

void showHistory(void) {
    FILE *fp = fopen(HISTORY_FILE, "r");
    char line[150];

    if (fp == NULL) {
        printf("\nNo transaction history found.\n");
        return;
    }

    printf("\n--- Transaction History ---\n");

    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }

    fclose(fp);
}

int main(void) {
    struct Account account;
    int choice, enteredPIN;

    printf("================================\n");
    printf("       ATM SIMULATION SYSTEM\n");
    printf("================================\n");

    if (!loadAccount(&account)) {
        printf("\nNo account found. Create one first.\n");
        createAccount(&account);

        if (!loadAccount(&account)) {
            printf("Unable to load account. Exiting.\n");
            return 1;
        }
    }

    printf("\nEnter your account number: ");
    int enteredAccount;
    scanf("%d", &enteredAccount);

    printf("Enter your PIN: ");
    scanf("%d", &enteredPIN);

    if (enteredAccount != account.accountNumber ||
        enteredPIN != account.pin) {
        printf("\nInvalid account number or PIN!\n");
        return 0;
    }

    printf("\nLogin successful!\n");

    do {
        printf("\n========== ATM MENU ==========\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Change PIN\n");
        printf("5. Transaction History\n");
        printf("6. Exit\n");
        printf("==============================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkBalance(account);
                break;

            case 2:
                deposit(&account);
                break;

            case 3:
                withdraw(&account);
                break;

            case 4:
                changePIN(&account);
                break;

            case 5:
                showHistory();
                break;

            case 6:
                printf("Thank you for using our ATM!\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 6);

    return 0;
}
