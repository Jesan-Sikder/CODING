#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Room {
    int number;
    int booked;
    char name[50];
    char nid[20];
    char phone[15];
    int guests;
    int kids;
    int duration;
    float cost;
    struct Room* next;
};
typedef struct Room Room;
Room* head = NULL;

int choice, roomNumber, days, guests, kids;
char name[50], nid[20], phone[15];
float cost, additionalCost;

void addRoomb(int number) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->number = number;
    newRoom->booked = 0;
    newRoom->name[0] = '\0';   // Initialize name as an empty string
    newRoom->nid[0] = '\0';    // Initialize nid as an empty string
    newRoom->phone[0] = '\0';  // Initialize phone as an empty string
    newRoom->guests = 0;
    newRoom->kids = 0;
    newRoom->duration = 0;
    newRoom->cost = 0.0;
    newRoom->next = head;
    head = newRoom;
}

void addRooma(int number) {
    if (head == NULL) {
        addRoomb(number);
    } else {
        Room* newRoom = (Room*)malloc(sizeof(Room));
        newRoom->number = number;
        newRoom->booked = 0;
        newRoom->name[0] = '\0';   // Initialize name as an empty string
        newRoom->nid[0] = '\0';    // Initialize nid as an empty string
        newRoom->phone[0] = '\0';  // Initialize phone as an empty string
        newRoom->guests = 0;
        newRoom->kids = 0;
        newRoom->duration = 0;
        newRoom->cost = 0.0;
        newRoom->next = NULL;

        Room* i = head;
        while (i->next != NULL) {
            i = i->next;
        }
        i->next = newRoom;
    }
}

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
                // Initialize name, nid, and phone directly
                strncpy(temp->name, name, sizeof(temp->name) - 1);
                temp->name[sizeof(temp->name) - 1] = '\0';  // Ensure null-termination
                strncpy(temp->nid, nid, sizeof(temp->nid) - 1);
                temp->nid[sizeof(temp->nid) - 1] = '\0';    // Ensure null-termination
                strncpy(temp->phone, phone, sizeof(temp->phone) - 1);
                temp->phone[sizeof(temp->phone) - 1] = '\0';  // Ensure null-termination
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

void cancelRoom(int number) {
    Room* temp = head;
    while (temp != NULL) {
        if (temp->number == number) {
            if (!temp->booked) {
                printf("Room %d is not booked.\n", number);
                return;
            } else {
                temp->booked = 0;
                temp->name[0] = '\0';    // Clear the name
                temp->nid[0] = '\0';     // Clear the nid
                temp->phone[0] = '\0';   // Clear the phone
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

void extendStay(int number, int days, float additionalCost) {
    Room* temp = head;
    while (temp != NULL) {
        if (temp->number == number) {
            if (!temp->booked) {
                printf("Room %d is not booked, cannot extend stay.\n", number);
                return;
            } else {
                temp->duration += days;
                temp->cost += additionalCost;
                printf("Extended stay for Room %d by %d days. Total stay: %d days. New cost: %.2f\n",
                       number, days, temp->duration, temp->cost);
                return;
            }
        }
        temp = temp->next;
    }
    printf("Room %d not found.\n", number);
}

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

void showBookings() {
    Room* temp = head;
    printf("Booked Rooms:\n");
    printf("Room Number\tCustomer Name\t\tDays\tPrice\t\tGuests\t\tKids\n");
    printf("-------------------------------------------------------------------------------------------------------\n");
    while (temp != NULL) {
        if (temp->booked) {
            printf("%-12d\t%-20s\t%-4d\t%.2f\t\t%-6d\t",
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

void freeRooms() {
    Room* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void initializeRooms() {
    for (int floor = 1; floor <= 5; floor++) {
        for (int room = 1; room <= 10; room++) {
            int roomNumber = (floor * 100) + room;
            addRooma(roomNumber);
        }
    }
}

int main() {
    initializeRooms();

    while (1) {
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

            Room* temp = head;
            while (temp != NULL) {
                if (temp->number == roomNumber) {
                    if (temp->booked) {
                        printf("Room %d is already booked.\n", roomNumber);
                        break;
                    }
                    break;
                }
                temp = temp->next;
            }

            if (temp != NULL && !temp->booked) {
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
            }
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
            printf("Enter additional cost: ");
            scanf("%f", &additionalCost);
            extendStay(roomNumber, days, additionalCost);
        } else if (choice == 6) {
            printf("Exiting...\n");
            freeRooms();
            break;
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }
}
