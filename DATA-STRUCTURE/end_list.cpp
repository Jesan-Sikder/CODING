#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};
typedef struct Node s;

void print(s *i)
{
    while (i != NULL)
    {
        printf("Element: %d\n", i->data);
        i = i->next;
    }
}





// Case 3
s * insertAtEnd(s *head, int data){
    s * newnode = (s *) malloc(sizeof(s));
    newnode->data = data;
    s * p = head;

    while(p->next!=NULL){
        p = p->next;
    }
    p->next = newnode;
    newnode->next = NULL;
    return head;
}



int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = NULL;

    printf("Linked list before insertion\n");
    print(head);
    
    head = insertAtEnd(head, 56);
    
    printf("\nLinked list after insertion\n");
    print(head);

    
    return 0;
}