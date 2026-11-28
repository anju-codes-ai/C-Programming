
#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "hotel.dat"
#define TEMP_FILE "temp.dat"
#define TOTAL_ROOMS 20
#define ROOM_RATE 1500.0

struct Booking {
    int bookingID;
    char guestName[50];
    int roomNumber;
    int days;
    double bill;
};

int roomBooked(int roomNumber) {
    struct Booking b;
    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL)
        return 0;

    while (fread(&b, sizeof(b), 1, fp) == 1) {
        if (b.roomNumber == roomNumber) {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

int generateBookingID(void) {
    struct Booking b;
    int maxID = 1000;

    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL)
        return maxID + 1;

    while (fread(&b, sizeof(b), 1, fp) == 1) {
        if (b.bookingID > maxID)
            maxID = b.bookingID;
    }

    fclose(fp);
    return maxID + 1;
}

void bookRoom(void) {
    struct Booking b;

    printf("\nEnter Guest Name: ");
    scanf(" %49[^\n]", b.guestName);

    printf("Enter Room Number (1-20): ");
    scanf("%d", &b.roomNumber);

    if (b.roomNumber < 1 || b.roomNumber > TOTAL_ROOMS) {
        printf("Invalid room number!\n");
        return;
    }

    if (roomBooked(b.roomNumber)) {
        printf("Room is already booked!\n");
        return;
    }

    printf("Enter Number of Days: ");
    scanf("%d", &b.days);

    if (b.days <= 0) {
        printf("Invalid number of days!\n");
        return;
    }

    b.bookingID = generateBookingID();
    b.bill = b.days * ROOM_RATE;

    FILE *fp = fopen(FILE_NAME, "ab");

    if (fp == NULL) {
        printf("Unable to open file!\n");
        return;
    }

    if (fwrite(&b, sizeof(b), 1, fp) == 1) {
        printf("\nRoom booked successfully!\n");
        printf("Booking ID: %d\n", b.bookingID);
        printf("Room Number: %d\n", b.roomNumber);
        printf("Total Bill: Rs. %.2f\n", b.bill);
    } else {
        printf("Unable to save booking.\n");
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

    printf("\n========== HOTEL BOOKINGS ==========\n");

    while (fread(&b, sizeof(b), 1, fp) == 1) {
        printf("\nBooking ID: %d\n", b.bookingID);
        printf("Guest Name: %s\n", b.guestName);
        printf("Room Number: %d\n", b.roomNumber);
        printf("Days: %d\n", b.days);
        printf("Total Bill: Rs. %.2f\n", b.bill);
    }

    fclose(fp);
}

void searchBooking(void) {
    struct Booking b;
    int id, found = 0;

    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL) {
        printf("No bookings available.\n");
        return;
    }

    printf("\nEnter Booking ID: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(b), 1, fp) == 1) {
        if (b.bookingID == id) {
            printf("\nBooking Found!\n");
            printf("Guest: %s\n", b.guestName);
            printf("Room: %d\n", b.roomNumber);
            printf("Days: %d\n", b.days);
            printf("Bill: Rs. %.2f\n", b.bill);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Booking not found!\n");

    fclose(fp);
}

void availableRooms(void) {
    int room, count = 0;

    printf("\nAvailable Rooms:\n");

    for (room = 1; room <= TOTAL_ROOMS; room++) {
        if (!roomBooked(room)) {
            printf("%d ", room);
            count++;
        }
    }

    printf("\nTotal Available Rooms: %d\n", count);
}

void checkout(void) {
    struct Booking b;
    int id, found = 0;

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

    printf("\nEnter Booking ID for Checkout: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(b), 1, fp) == 1) {
        if (b.bookingID == id) {
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

    printf("Checkout completed successfully!\n");
}

int main(void) {
    int choice;

    do {
        printf("\n================================\n");
        printf("       HOTEL MANAGEMENT SYSTEM\n");
        printf("================================\n");
        printf("1. Book Room\n");
        printf("2. Display Bookings\n");
        printf("3. Search Booking\n");
        printf("4. Available Rooms\n");
        printf("5. Checkout\n");
        printf("6. Exit\n");

        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookRoom();
                break;

            case 2:
                displayBookings();
                break;

            case 3:
                searchBooking();
                break;

            case 4:
                availableRooms();
                break;

            case 5:
                checkout();
                break;

            case 6:
                printf("Thank you for using the system!\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 6);

    return 0;
}
