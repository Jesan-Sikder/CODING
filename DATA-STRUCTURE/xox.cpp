#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define NAME_SIZE 50
#define NID_SIZE 20
#define PHONE_SIZE 15

// Room structure
typedef struct Room {
    int number;
    int booked; // 0 for available, 1 for booked
    char name[NAME_SIZE];
    char nid[NID_SIZE];
    char phone[PHONE_SIZE];
    int guests;
    int kids; // 1 if there are kids, 0 otherwise
    int duration; // Number of days
    float cost; // Price of the room
    struct Room* next;
} Room;

// Head of the list
Room* head = NULL;

// Function prototypes
// void addRoom(int number);
// void bookRoom(int number, const char* name, const char* nid, const char* phone, 
//               int duration, float cost, int guests, int kids);
// void cancelRoom(int number);
// void showRooms();
// void showBookings();
// void extendStay(int number, int days, float additionalCost);
// void freeRooms();
// void initializeRooms();

// Add a room to the list
void addRoom(int number) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->number = number;
    newRoom->booked = 0; // Initially available
    strcpy(newRoom->name, "");
    strcpy(newRoom->nid, "");
    strcpy(newRoom->phone, "");
    newRoom->guests = 0;
    newRoom->kids = 0;
    newRoom->duration = 0;
    newRoom->cost = 0.0;
    newRoom->next = head;
    head = newRoom;
}

// Book a room
void bookRoom(int number, const char* name, const char* nid, const char* phone, 
              int duration, float cost, int guests, int kids) {
    Room* temp = head;
    while (temp != NULL) {
        if (temp->number == number) {
            if (temp->booked) {
                printf("Room %d is already booked.\n", number);
                return;
            } else {
                temp->booked = 1;
                strcpy(temp->name, name);
                strcpy(temp->nid, nid);
                strcpy(temp->phone, phone);
                temp->duration = duration;
                temp->cost = cost;
                temp->guests = guests;
                temp->kids = kids;
                printf("Room %d booked for %s (NID: %s) for %d days at %.2f.\n", 
                       number, name, nid, duration, cost);
                return;
            }
        }
        temp = temp->next;
    }
    printf("Room %d not found.\n", number);
}

// Cancel a booking
void cancelRoom(int number) {
    Room* temp = head;
    while (temp != NULL) {
        if (temp->number == number) {
            if (!temp->booked) {
                printf("Room %d is not booked.\n", number);
                return;
            } else {
                temp->booked = 0;
                strcpy(temp->name, "");
                strcpy(temp->nid, "");
                strcpy(temp->phone, "");
                temp->guests = 0;
                temp->kids = 0;
                temp->duration = 0;
                temp->cost = 0.0;
                printf("Booking for Room %d canceled.\n", number);
                return;
            }
        }
        temp = temp->next;
    }
    printf("Room %d not found.\n", number);
}

// Extend a stay
void extendStay(int number, int days, float additionalCost) {
    Room* temp = head;
    while (temp != NULL) {
        if (temp->number == number) {
            if (!temp->booked) {
                printf("Room %d is not booked, cannot extend stay.\n", number);
                return;
            } else {
                temp->duration += days;
                temp->cost += additionalCost; // Increase the cost
                printf("Extended stay for Room %d by %d days. Total stay: %d days. New cost: %.2f\n", 
                       number, days, temp->duration, temp->cost);
                return;
            }
        }
        temp = temp->next;
    }
    printf("Room %d not found.\n", number);
}

// Show all rooms
void showRooms() {
    Room* temp = head;
    printf("Room Number\tStatus\t\tCustomer Name\tDays\tPrice\n");
    printf("------------------------------------------------------------------------------------\n");
    while (temp != NULL) {
        printf("%d\t\t", temp->number);
        if (temp->booked) {
            printf("Booked\t\t%s\t\t%d\t%.2f\n", temp->name, temp->duration, temp->cost);
        } else {
            printf("Available\tN/A\t\t0\t0.00\n");
        }
        temp = temp->next;
    }
}

// Show all bookings
void showBookings() {
    Room* temp = head;
    printf("Booked Rooms:\n");
    printf("Room Number\tCustomer Name\t\tDays\tPrice\t\tGuests\t\tKids\n");
    printf("-------------------------------------------------------------------------------------------------------\n");
    while (temp != NULL) {
        if (temp->booked) {
            printf("%-12d\t%-20s\t%-4d\t%.2f\t%-6d\t", 
                   temp->number, temp->name, temp->duration, 
                   temp->cost, temp->guests);
            if (temp->kids) {
                printf("\tYes\n");
            } else {
                printf("\tNo\n");
            }
        }
        temp = temp->next;
    }
}

// Free the list
void freeRooms() {
    Room* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Initialize rooms
void initializeRooms() {
    for (int i = 1; i <= MAX_ROOMS; i++) {
        addRoom(i);
    }
}

// Main function
int main() {
    int choice, roomNumber, days, guests, kids;
    char name[NAME_SIZE], nid[NID_SIZE], phone[PHONE_SIZE];
    float cost, additionalCost;

    initializeRooms();

    do {
        printf("\nHotel Management System\n");
        printf("1. Show All Rooms\n");
        printf("2. Book Room\n");
        printf("3. Cancel Booking\n");
        printf("4. View Bookings\n");
        printf("5. Extend Stay\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            showRooms();
        } else if (choice == 2) {
            printf("Enter room number: ");
            scanf("%d", &roomNumber);
            printf("Enter customer name: ");
            scanf(" %[^\n]", name);
            printf("Enter customer NID: ");
            scanf(" %[^\n]", nid);
            printf("Enter customer phone: ");
            scanf(" %[^\n]", phone);
            printf("Enter stay duration (days): ");
            scanf("%d", &days);
            printf("Enter price: ");
            scanf("%f", &cost);
            printf("Enter number of guests: ");
            scanf("%d", &guests);
            printf("Are there kids? (1 for Yes, 0 for No): ");
            scanf("%d", &kids);
            bookRoom(roomNumber, name, nid, phone, days, cost, guests, kids);
        } else if (choice == 3) {
            printf("Enter room number to cancel: ");
            scanf("%d", &roomNumber);
            cancelRoom(roomNumber);
        } else if (choice == 4) {
            showBookings();
        } else if (choice == 5) {
            printf("Enter room number to extend: ");
            scanf("%d", &roomNumber);
            printf("Enter additional days: ");
            scanf("%d", &days);
            printf("Enter additional cost: ");  // Ask for additional cost
            scanf("%f", &additionalCost);
            extendStay(roomNumber, days, additionalCost); // Pass the additional cost
        } else if (choice == 6) {
            printf("Exiting...\n");
            freeRooms();
        } else {
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
