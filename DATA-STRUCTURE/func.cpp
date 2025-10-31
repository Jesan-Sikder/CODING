// #include <stdio.h>

// int fun(int a, int b) {
//     return a + b; // Directly return the sum of a and b
// }

// int main() {
//     int a, b, sum;
//     printf("Enter two integers: ");
//     scanf("%d %d", &a, &b);
    
//     sum = fun(a, b); // Call the fun function to calculate the sum
//     printf("The sum is: %d\n", sum); // Print the sum

//     return 0; // Return 0 to indicate successful completion
// }


#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    char c;
    struct node * prev;
    struct node * next;


};
typedef struct node s;
void print(s*i){
    while(i != NULL){
        printf("element : %d\n", i->data);
        printf("element : %c\n", i->c);

        i=i->next;
    }
}
//********************************************* */
// s*search(s*head,int data,char c){
    
// s*newnode=(s*)malloc(sizeof(s));
//     newnode->data=545;
//     newnode->c='j';
//     newnode->next=NULL;
//     newnode->prev=NULL;
//     s *ptr=head;
//     while (ptr->data != data && ptr->c !='c')
//     {
//         ptr=ptr->next;
//     }
//     newnode->next=ptr->next;
//     ptr->next=newnode;
//     newnode->prev=ptr;
//     newnode->next->prev=newnode;
//     return head;

// }
//******************************************************** */
int main(){
    s*head = (s*)malloc(sizeof(s));
    s*second = (s*)malloc(sizeof(s));
    s*third = (s*)malloc(sizeof(s));

    head->data=1;
    head->next=second;
    head->c='a';
    second->c='b';

    third->c='c';

    head->prev=NULL;
    second->prev=head;
    second->data=2;
    second->next=third;
    third ->prev=second;
    third->data=3;
    third->next = NULL;

    s*newnode=(s*)malloc(sizeof(s));
    newnode->data=545;
    newnode->c='j';
    newnode->next=NULL;
    newnode->prev=NULL;
    s *ptr=head;
    while (ptr->data != 1 && ptr->c !='a')
    {
        ptr=ptr->next;
    }
    newnode->next=ptr->next;
    ptr->next=newnode;
    newnode->prev=ptr;
    newnode->next->prev=newnode;


// head=search(head,1,'a');


ptr= head;
while(ptr->next->data != 3 ){
    ptr=ptr->next;

}
free(ptr->next);
ptr->next =NULL;

    print(head);


}




























#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Case 1
struct Node * insertAtFirst(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = head;
    return ptr; 
}

// Case 2
struct Node * insertAtIndex(struct Node *head, int data, int index){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;

    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// Case 3
struct Node * insertAtEnd(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head;

    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// Case 4
struct Node * insertAfterNode(struct Node *head, struct Node *prevNode, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    
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
    linkedListTraversal(head);
    // head = insertAtFirst(head, 56);
    // head = insertAtIndex(head, 56, 1);
    // head = insertAtEnd(head, 56);
    head = insertAfterNode(head, third, 45);
    printf("\nLinked list after insertion\n");
    linkedListTraversal(head);

    
    return 0;
}