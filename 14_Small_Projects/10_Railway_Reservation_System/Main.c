
#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "bookings.dat"
#define TEMP_FILE "temp.dat"
#define TOTAL_SEATS 50
#define FARE_PER_SEAT 250.0

struct Booking {
    int pnr;
    char passengerName[50];
    int age;
    int seats;
    double fare;
};

int generatePNR(void) {
    struct Booking b;
    int maxPNR = 1000;

    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL)
        return maxPNR + 1;

    while (fread(&b, sizeof(b), 1, fp) == 1) {
        if (b.pnr > maxPNR)
            maxPNR = b.pnr;
    }

    fclose(fp);
    return maxPNR + 1;
}

int bookedSeats(void) {
    struct Booking b;
    int total = 0;

    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL)
        return 0;

    while (fread(&b, sizeof(b), 1, fp) == 1)
        total += b.seats;

    fclose(fp);
    return total;
}

void bookTicket(void) {
    struct Booking b;

    int available = TOTAL_SEATS - bookedSeats();

    printf("\nAvailable Seats: %d\n", available);

    if (available <= 0) {
        printf("No seats available!\n");
        return;
    }

    printf("Enter Passenger Name: ");
    scanf(" %49[^\n]", b.passengerName);

    printf("Enter Passenger Age: ");
    scanf("%d", &b.age);

    if (b.age <= 0 || b.age > 120) {
        printf("Invalid age!\n");
        return;
    }

    printf("Enter Number of Seats: ");
    scanf("%d", &b.seats);

    if (b.seats <= 0 || b.seats > available) {
        printf("Invalid seat selection!\n");
        return;
    }

    b.pnr = generatePNR();
    b.fare = b.seats * FARE_PER_SEAT;

    FILE *fp = fopen(FILE_NAME, "ab");

    if (fp == NULL) {
        printf("Unable to open booking file!\n");
        return;
    }

    if (fwrite(&b, sizeof(b), 1, fp) == 1) {
        printf("\nTicket booked successfully!\n");
        printf("PNR Number: %d\n", b.pnr);
        printf("Passenger: %s\n", b.passengerName);
        printf("Seats: %d\n", b.seats);
        printf("Total Fare: Rs. %.2f\n", b.fare);
    } else {
        printf("Booking could not be saved.\n");
    }

    fclose(fp);
}

void displayBookings(void) {
    struct Booking b;

    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL) {
        printf("\nNo bookings found.\n");
        return;
    }

    printf("\n========== ALL BOOKINGS ==========\n");

    while (fread(&b, sizeof(b), 1, fp) == 1) {
        printf("\nPNR: %d\n", b.pnr);
        printf("Passenger: %s\n", b.passengerName);
        printf("Age: %d\n", b.age);
        printf("Seats: %d\n", b.seats);
        printf("Fare: Rs. %.2f\n", b.fare);
    }

    fclose(fp);
}

void searchBooking(void) {
    struct Booking b;
    int pnr, found = 0;

    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL) {
        printf("No bookings available.\n");
        return;
    }

    printf("\nEnter PNR Number: ");
    scanf("%d", &pnr);

    while (fread(&b, sizeof(b), 1, fp) == 1) {
        if (b.pnr == pnr) {
            printf("\nBooking Found!\n");
            printf("PNR: %d\n", b.pnr);
            printf("Passenger: %s\n", b.passengerName);
            printf("Age: %d\n", b.age);
            printf("Seats: %d\n", b.seats);
            printf("Fare: Rs. %.2f\n", b.fare);

            found = 1;
            break;
        }
    }

    if (!found)
        printf("Booking not found!\n");

    fclose(fp);
}

void cancelTicket(void) {
    struct Booking b;
    int pnr, found = 0;

    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL) {
        printf("No bookings available.\n");
        return;
    }

    FILE *temp = fopen(TEMP_FILE, "wb");

    if (temp == NULL) {
        printf("Unable to create temporary file.\n");
        fclose(fp);
        return;
    }

    printf("\nEnter PNR to cancel: ");
    scanf("%d", &pnr);

    while (fread(&b, sizeof(b), 1, fp) == 1) {
        if (b.pnr == pnr) {
            found = 1;
            continue;
        }

        if (fwrite(&b, sizeof(b), 1, temp) != 1) {
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
        printf("Booking not found!\n");
        return;
    }

    if (remove(FILE_NAME) != 0) {
        printf("Could not replace booking file.\n");
        return;
    }

    if (rename(TEMP_FILE, FILE_NAME) != 0) {
        printf("Replacement failed. Recovery file: temp.dat\n");
        return;
    }

    printf("Ticket cancelled successfully!\n");
}

void showAvailableSeats(void) {
    int available = TOTAL_SEATS - bookedSeats();

    printf("\nTotal Seats: %d\n", TOTAL_SEATS);
    printf("Booked Seats: %d\n", bookedSeats());
    printf("Available Seats: %d\n", available);
}

int main(void) {
    int choice;

    do {
        printf("\n================================\n");
        printf("    RAILWAY RESERVATION SYSTEM\n");
        printf("================================\n");
        printf("1. Book Ticket\n");
        printf("2. Display All Bookings\n");
        printf("3. Search Booking\n");
        printf("4. Cancel Ticket\n");
        printf("5. Available Seats\n");
        printf("6. Exit\n");

        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookTicket();
                break;

            case 2:
                displayBookings();
                break;

            case 3:
                searchBooking();
                break;

            case 4:
                cancelTicket();
                break;

            case 5:
                showAvailableSeats();
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
