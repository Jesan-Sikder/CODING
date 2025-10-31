#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
};
typedef struct node s;
void print(s *i)
{
    while (i != NULL)
    {
        printf("Element: %d\n", i->data);
        i = i->next;
    }
}

// Case 1
s * insertAtFirst(s *head, int data){
    s * i = (s *) malloc(sizeof(s));
    i->data = data;

    i->next = head;
    return i; 
}

// Case 2
s * insertAtIndex(s *head, int data, int index){
    s * i = (s *) malloc(sizeof(s));
    s * p = head;
    int j = 0;

    while (j != index-1)
    {
        p = p->next;
        i++;
    }
    i->data = data;
    i->next = p->next;
    p->next = i;
    return head;
}

// Case 3
s * insertAtEnd(s *head, int data){
    s * i = (s *) malloc(sizeof(s));
    i->data = data;
    s * p = head;

    while(p->next!=NULL){
        p = p->next;
    }
    p->next = i;
    i->next = NULL;
    return head;
}

// Case 4
s * insertAfterNode(s *head, s *prevNode, int data){
    s * i = (s *) malloc(sizeof(s));
    i->data = data;

    i->next = prevNode->next;
    prevNode->next = i;

    
    return head;
}


int main(){
    s *head;
    s *second;
    s *third;
    s *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (s *)malloc(sizeof(s));
    second = (s *)malloc(sizeof(s));
    third = (s *)malloc(sizeof(s));
    fourth = (s *)malloc(sizeof(s));

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
    // head = insertAtFirst(head, 56);
    // head = insertAtIndex(head, 56, 1);
    head = insertAtEnd(head, 56);
    // head = insertAfterNode(head, third, 45);
    printf("\nLinked list after insertion\n");
    print(head);

    
    return 0;
}
