// #include <stdio.h>
// #include <stdlib.h>
// struct node
// {
//     int a;
//     struct node *next;
// };
// typedef struct node s;
// s *start = NULL;

// void print()
// {
//     s *i = start;
//     while (i != NULL)
//     {
//         printf("Printing linked list....\n");
//         printf("%d\n", i->a);
//         i = i->next;
//     }
// }

// void insertB()
// {
//     s *newnode = (s *)malloc(sizeof(s));
//     int x;
//     printf("Enter data for newnode:\n");
//     scanf("%d", &x);
//     newnode->a = x;
//     newnode->next = NULL;

//     newnode->next = start;
//     start = newnode;
// }

// void insertL()
// {
//     if (start == NULL)
//     {
//         insertB();
//     }
//     else
//     {
//         s *newnode = (s *)malloc(sizeof(s));
//         int x;
//         printf("Enter data for newnode:\n");
//         scanf("%d", &x);
//         newnode->a = x;
//         newnode->next = NULL;
//         s *i = start;
//         while (i->next = NULL)
//         {
//             i = i->next;
//         }
//         i->next = newnode;
//     }
// }

// int main()
// {
//     insertB();
//     insertL();
//     insertL();

//     print();
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

struct node {
    int a;
    struct node *next;
};

typedef struct node s;
s *start = NULL;

void print() {
    s *i = start;
    // if (i == NULL) {
    //     printf("The linked list is empty.\n");
    //     return;
    // }
    printf("Printing linked list:\n");
    while (i != NULL) {
        printf("%d\n", i->a);
        i = i->next;
    }
}

void insertB() {
    s *newnode = (s *)malloc(sizeof(s));
    // if (!newnode) {
    //     printf("Memory allocation failed.\n");
    //     return;
    // }
    
    int x;
    printf("Enter data for newnode:\n");
    scanf("%d", &x);
    newnode->a = x;
    newnode->next = start;
    start = newnode;
}

void insertL() {
    s *newnode = (s *)malloc(sizeof(s));
    // if (!newnode) {
    //     printf("Memory allocation failed.\n");
    //     return;
    // }

    int x;
    printf("Enter data for newnode:\n");
    scanf("%d", &x);
    newnode->a = x;
    newnode->next = NULL;

    if (start == NULL) {
        start = newnode; // If the list is empty, make the new node the start.
    } else {
        s *i = start;
        while (i->next != NULL) { // Corrected condition from '=' to '!='
            i = i->next;
        }
        i->next = newnode;
    }
}

int main() {
    insertB();
    insertL();
    // insertL();

    print();
    return 0;
}
/*write a c program to print some node in a linkd list  as the node will insert at beginning and insert at  last  by calling functions */