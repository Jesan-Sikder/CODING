#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define NAME_LENGTH 50
#define NID_LENGTH 20
#define PHONE_LENGTH 15

// Structure to represent a room
typedef struct Room {
    int roomNumber;
    int isBooked; // 0 for available, 1 for booked
    char customerName[NAME_LENGTH];
    char customerNID[NID_LENGTH]; // Customer NID
    char customerPhone[PHONE_LENGTH]; // Customer phone number
    int numberOfPeople; // Number of people staying
    int hasChildren; // 1 if there are children under 18, 0 otherwise
    int stayDuration; // Number of days for the stay
    float price; // Price for the room
    struct Room* next;
} Room;

// Head of the linked list
Room* head = NULL;

// Function prototypes
void addRoom(int roomNumber);
void bookRoom(int roomNumber, const char* customerName, const char* customerNID, const char* customerPhone, 
              int stayDuration, float price, int numberOfPeople, int hasChildren);
void cancelBooking(int roomNumber);
void displayRooms();
void displayBookings();
void extendStay(int roomNumber, int additionalDays);
void freeRooms();
void initializeRooms();

// Function to add a room
void addRoom(int roomNumber) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->roomNumber = roomNumber;
    newRoom->isBooked = 0; // Initially available
    strcpy(newRoom->customerName, "");
    strcpy(newRoom->customerNID, "");
    strcpy(newRoom->customerPhone, "");
    newRoom->numberOfPeople = 0; // Initial number of people
    newRoom->hasChildren = 0; // No children by default
    newRoom->stayDuration = 0; // Initial stay duration
    newRoom->price = 0.0; // Initial price
    newRoom->next = head;
    head = newRoom;
}

// Function to book a room
void bookRoom(int roomNumber, const char* customerName, const char* customerNID, const char* customerPhone, 
              int stayDuration, float price, int numberOfPeople, int hasChildren) {
    Room* temp = head;
    while (temp != NULL) {
        if (temp->roomNumber == roomNumber) {
            if (temp->isBooked) {
                printf("Room %d is already booked.\n", roomNumber);
                return;
            } else {
                temp->isBooked = 1;
                strcpy(temp->customerName, customerName);
                strcpy(temp->customerNID, customerNID);
                strcpy(temp->customerPhone, customerPhone);
                temp->stayDuration = stayDuration; // Set stay duration
                temp->price = price; // Set price for the room
                temp->numberOfPeople = numberOfPeople; // Set number of people
                temp->hasChildren = hasChildren; // Set whether there are children
                printf("Room %d booked successfully for %s (NID: %s, Phone: %s) for %d days at a price of %.2f.\n", 
                       roomNumber, customerName, customerNID, customerPhone, stayDuration, price);
                return;
            }
        }
        temp = temp->next;
    }
    printf("Room %d not found.\n", roomNumber);
}

// Function to cancel a booking
void cancelBooking(int roomNumber) {
    Room* temp = head;
    while (temp != NULL) {
        if (temp->roomNumber == roomNumber) {
            if (!temp->isBooked) {
                printf("Room %d is not booked.\n", roomNumber);
                return;
            } else {
                temp->isBooked = 0;
                strcpy(temp->customerName, "");
                strcpy(temp->customerNID, "");
                strcpy(temp->customerPhone, "");
                temp->numberOfPeople = 0; // Reset number of people
                temp->hasChildren = 0; // Reset children status
                temp->stayDuration = 0; // Reset stay duration
                temp->price = 0.0; // Reset price
                printf("Booking for Room %d has been canceled.\n", roomNumber);
                return;
            }
        }
        temp = temp->next;
    }
    printf("Room %d not found.\n", roomNumber);
}

// Function to extend stay
void extendStay(int roomNumber, int additionalDays) {
    Room* temp = head;
    while (temp != NULL) {
        if (temp->roomNumber == roomNumber) {
            if (!temp->isBooked) {
                printf("Room %d is not booked, cannot extend stay.\n", roomNumber);
                return;
            } else {
                temp->stayDuration += additionalDays; // Increase stay duration
                printf("Extended stay for Room %d by %d days. Total stay: %d days.\n", roomNumber, additionalDays, temp->stayDuration);
                return;
            }
        }
        temp = temp->next;
    }
    printf("Room %d not found.\n", roomNumber);
}

// Function to display all rooms
void displayRooms() {
    Room* temp = head;
    printf("Room Number\tStatus\t\tCustomer Name\tStay Duration (Days)\tPrice\n");
    printf("--------------------------------------------------------------------------------\n");
    while (temp != NULL) {
        printf("%d\t\t", temp->roomNumber);
        if (temp->isBooked) {
            printf("Booked\t\t%s\t\t%d\t\t\t%.2f\n", temp->customerName, temp->stayDuration, temp->price);
        } else {
            printf("Available\tN/A\t\t0\t\t\t0.00\n");
        }
        temp = temp->next;
    }
}

// Function to display all bookings
void displayBookings() {
    Room* temp = head;
    printf("Currently Booked Rooms:\n");
    printf("Room Number\tCustomer Name\tStay Duration (Days)\tPrice\tNumber of People\tChildren Under 18\n");
    printf("---------------------------------------------------------------------------------------------\n");
    while (temp != NULL) {
        if (temp->isBooked) {
            printf("%d\t\t%s\t\t%d\t\t\t%.2f\t%d\t\t\t", 
                   temp->roomNumber, temp->customerName, temp->stayDuration, 
                   temp->price, temp->numberOfPeople);
            if (temp->hasChildren) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
        temp = temp->next;
    }
}

// Function to free the linked list
void freeRooms() {
    Room* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to initialize rooms
void initializeRooms() {
    for (int i = 1; i <= MAX_ROOMS; i++) {
        addRoom(i);
    }
}

// Main function
int main() {
    int choice, roomNumber, stayDuration, additionalDays, numberOfPeople, hasChildren;
    char customerName[NAME_LENGTH];
    char customerNID[NID_LENGTH];
    char customerPhone[PHONE_LENGTH];
    float price;

    initializeRooms(); // Initialize rooms

    do {
        printf("\nHotel Management System\n");
        printf("1. Display All Rooms\n");
        printf("2. Book Room\n");
        printf("3. Cancel Booking\n");
        printf("4. View Bookings\n");
        printf("5. Extend Stay\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            displayRooms();
        } else if (choice == 2) {
            printf("Enter room number to book: ");
            scanf("%d", &roomNumber);
            printf("Enter customer name: ");
            scanf(" %[^\n]", customerName); // To read string with spaces
            printf("Enter customer NID: ");
            scanf(" %[^\n]", customerNID);
            printf("Enter customer phone number: ");
            scanf(" %[^\n]", customerPhone);
            printf("Enter stay duration (in days): ");
            scanf("%d", &stayDuration);
            printf("Enter price for the room: ");
            scanf("%f", &price);
            printf("Enter number of people staying: ");
            scanf("%d", &numberOfPeople);
            printf("Are there children under 18 staying? (1 for Yes, 0 for No): ");
            scanf("%d", &hasChildren);
            bookRoom(roomNumber, customerName, customerNID, customerPhone, 
                     stayDuration, price, numberOfPeople, hasChildren);
        } else if (choice == 3) {
            printf("Enter room number to cancel booking: ");
            scanf("%d", &roomNumber);
            cancelBooking(roomNumber);
        } else if (choice == 4) {
            displayBookings();
        } else if (choice == 5) {
            printf("Enter room number to extend stay: ");
            scanf("%d", &roomNumber);
            printf("Enter additional days to extend: ");
            scanf("%d", &additionalDays);
            extendStay(roomNumber, additionalDays);
        } else if (choice == 6) {
            printf("Exiting...\n");
            freeRooms(); // Free allocated memory
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
