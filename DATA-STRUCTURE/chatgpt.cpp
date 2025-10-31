#include <stdio.h>
#include <stdlib.h>

struct student {
    int a;
    char b;
    struct student *next;
};

typedef struct student S;

S *start = NULL;

void printList() {
    S *current = start;
    while (current != NULL) {
        printf("%d %c\n", current->a, current->b);
        current = current->next;
    }
}

void insertLast() {
    printf("Inserting at the end:\n");
    S *newNode = (S *)malloc(sizeof(S));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    int data;
    char data2;
    printf("Insert data (integer character): ");
    scanf("%d %c", &data, &data2);

    newNode->a = data;
    newNode->b = data2;
    newNode->next = NULL;

    if (start == NULL) {
        start = newNode; // List was empty
    } else {
        S *current = start;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode; // Link new node to the end
    }
}

void insertBeginning() {
    printf("Inserting at the beginning:\n");
    S *newNode = (S *)malloc(sizeof(S));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    int data;
    char data2;
    printf("Insert data (integer character): ");
    scanf("%d %c", &data, &data2);

    newNode->a = data;
    newNode->b = data2;
    newNode->next = start; // Link new node to current start
    start = newNode; // Update start to new node
}

int main() {
    insertBeginning();
   
    

    // insertLast();
    printList();

    // Free allocated memory (optional, but good practice)
    S *current = start;
    while (current != NULL) {
        S *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
/*#include <stdio.h>
#include <stdlib.h>

struct student {
    int a;
    char b;
    struct student *next;
};

typedef struct student S;

S *start = NULL;

void printList() {
    S *current = start;
    while (current != NULL) {
        printf("%d %c\n", current->a, current->b);
        current = current->next;
    }
}

void insertLast() {
    printf("Inserting at the end:\n");
    S *newNode = (S *)malloc(sizeof(S));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }

    int data;
    char data2;
    printf("Insert data (integer character): ");
    scanf("%d %c", &data, &data2);

    newNode->a = data;
    newNode->b = data2;
    newNode->next = NULL;

    if (start == NULL) {
        start = newNode; // List was empty
    } else {
        S *current = start;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode; // Link new node to the end
    }
}

void insertBeginning() {
    printf("Inserting at the beginning:\n");
    S *newNode = (S *)malloc(sizeof(S));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }

    int data;
    char data2;
    printf("Insert data (integer character): ");
    scanf("%d %c", &data, &data2);

    newNode->a = data;
    newNode->b = data2;
    newNode->next = start; // Link new node to current start
    start = newNode; // Update start to new node
}

void deleteNode(int value) {
    S *current = start;
    S *previous = NULL;

    while (current != NULL && current->a != value) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    if (previous == NULL) {
        start = current->next; // Deleting the head node
    } else {
        previous->next = current->next; // Bypass the current node
    }

    free(current); // Free the memory of the deleted node
    printf("Deleted node with value %d.\n", value);
}

int main() {
    insertBeginning();
    insertLast();
    printList();

    int valueToDelete;
    printf("Enter the value to delete: ");
    scanf("%d", &valueToDelete);
    deleteNode(valueToDelete);
    printList();

    // Free allocated memory
    S *current = start;
    while (current != NULL) {
        S *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
*/