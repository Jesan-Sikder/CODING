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
