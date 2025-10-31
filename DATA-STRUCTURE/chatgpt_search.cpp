#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    char c;
    struct node* prev;
    struct node* next;
};

typedef struct node s;

void print(s* i) {
    while (i != NULL) {
        printf("Element: %d\n", i->data);
        printf("Character: %c\n", i->c);
        i = i->next;
    }
}

s* search(s* head, int data, char c) {
    s* ptr = head;
    // Search for the node with specified data and character
    while (ptr != NULL) {
        if (ptr->data == data && ptr->c == c) {
            break; // Node found
        }
        ptr = ptr->next;
    }

    // If the node is found, insert the new node
    if (ptr != NULL) {
        s* newnode = (s*)malloc(sizeof(s));
        newnode->data = 545;
        newnode->c = 'j';
        newnode->next = ptr->next;
        newnode->prev = ptr;

        // Adjust pointers
        ptr->next = newnode;
        if (newnode->next != NULL) {
            newnode->next->prev = newnode; // Adjust next node's prev
        }
    } else {
        printf("Node with data %d and character %c not found.\n", data, c);
    }

    return head;
}

int main() {
    s* head = (s*)malloc(sizeof(s));
    s* second = (s*)malloc(sizeof(s));
    s* third = (s*)malloc(sizeof(s));

    head->data = 1;
    head->c = 'a';
    head->next = second;
    head->prev = NULL;

    second->data = 2;
    second->c = 'b';
    second->next = third;
    second->prev = head;

    third->data = 3;
    third->c = 'c';
    third->next = NULL;
    third->prev = second;

    // Search and insert a new node after the node with data 1 and character 'a'
    head = search(head, 1, 'a');

    // Print the list
    print(head);

    // Free allocated memory (not shown here, but you should ideally free all nodes)

    return 0;
}
