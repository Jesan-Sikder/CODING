#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node * next;
     
};
typedef struct node s;



void print_list(s*i){
    while(i != NULL){
        printf("Element : %d\n",i->data);
        i=i->next;
    }

}

//insertion at first position
// s *insert_first(s *head, int data){
//     s *newnode = (s*) malloc(sizeof(s));
//     newnode->next = head;
//     newnode->data= data;
//     return newnode;
// }

// between node
s *insert_at_index(s *head, int data, int index){
    s *newnode = (s*) malloc(sizeof(s));
    s*p=head;
    int i =0;
    while(i !=index-1){
        p=p->next;
        i++;


    }
    newnode->data= data;
    newnode->next = p->next;
    p->next =newnode;
    return head;
}

int main(){
    s *head = (s*)malloc (sizeof (s));
    s *second = (s*)malloc (sizeof (s));
    s *third = (s*)malloc (sizeof (s));
    s *fourth = (s*)malloc (sizeof (s));
    
    head -> data = 1;
    head -> next= second;

    second ->data =2;
    second -> next = third;

     third ->data =3;
    third -> next = fourth;

    fourth ->data = 545;
    fourth -> next = NULL;

// main play now begin
print_list(head);
printf("\nInseting....\n\n");
head = insert_at_index(head,56,1);

print_list(head);

    return 0;



}