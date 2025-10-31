#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node s;
void linkedListTraversal(s *i)
{
    while (i != NULL)
    {
        printf("Element: %d\n", i->data);
        i = i->next;
    }
}

// Case 1: Deleting the first element from the linked list
s * deleteFirst(s * head){
    s * p = head;
    head = head->next;
    free(p);
    return head;
}

// Case 2: Deleting the element at a given index from the linked list
s * deleteAtIndex(s * head, int index){
    s *p = head;
    s *q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = q->next;
    free(q);
    return head;
}

// Case 3: Deleting the last element
s * deleteAtLast(s * head){
    s *p = head;
    s *q = head->next;
    while(q->next !=NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = NULL;
    free(q);
    return head;
}


//Case 4: Deleting the element with a given value from the linked list
// s * delete_given_value(s * head, int value){
//     s *p = head;
//     s *q = head->next;
//     while(q->data!=value && q->next!= NULL)
//     {
//         p = p->next;
//         q = q->next;
//     }
    
//     if(q->data == value)
//     {
//         p->next = q->next;
//         free(q);
//     }
    
//     return head;
// }
//hey!!!!!/*amar srity */
s * delete_given_value(s * head, int data){
    s *p = head;
    s *q = head->next;
    while(p->next ->data != data)
    {
        p = p->next;
        q = q->next;
    }
    
    if(q->data == data)
    {
        p->next = q->next;
        q->next =p;
                free(q);
    }
    
    return head;
}
//************************* */
//firt
s*jesan(s*head){
    s*p=head;
    head= head ->next;
    free(p);
    return head;
}
/****** */
int main()
{
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
    head->data = 4;
    head->next = second;

    // Link second and third nodes
    second->data = 3;
    second->next = third;

    // Link third and fourth nodes
    third->data = 8;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 1;
    fourth->next = NULL;

    // printf("Linked list before deletion\n");
    // linkedListTraversal(head);

// printf("\nafter deleting first one\n\n");
//     head = deleteFirst(head); 


// printf("\nafter deleting the index uwala one\n\n");

//     head = deleteAtIndex(head, 2);
    // head = deleteAtLast(head);


    printf("Linked list after deletion\n");
    head = delete_given_value(head,1);
    // head = jesan(head);
    linkedListTraversal(head);

    return 0;
}