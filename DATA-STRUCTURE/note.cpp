#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    
    struct node * next;

};
typedef struct node s;

// printing
void print_list(s*i){

while ( i!=NULL){
    printf("element : %d\n",i->data);
    i=i->next;
}
}


//case 1 : begining node

s*insert_begining(s*head,int data)
{
    s*newnode=(s*)malloc(sizeof(s));
    newnode->data=data;

    newnode->next= head;

    return newnode;


}



// for index
s*insert_by_index(s*head,int data,int index){
    s*newnode=(s*)malloc(sizeof(s));
    s*p =head;
    int i = 0;
    while (i != index-1){
        p = p->next;
        i++;
    }
    newnode->data=data;
    newnode->next= p->next;
    p->next=newnode;

    return head;



}

//insert at end
s*insert_at_end(s*head,int data){
    s*newnode= (s*)malloc(sizeof(s));
    newnode->data = data;
    s*p=head;

    while(p->next != NULL){
        p=p->next;
    }
    p->next =  newnode;
    newnode->next=NULL;
    return head;
}


//after a node boila dewa thakbe


s*insert_after_node(s*head,s*previous,int data){
    s*newnode= (s*)malloc(sizeof(s));
    newnode->data= data;
    newnode->next = previous->next;
    previous->next =newnode;
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
printf("normal printing\n");
print_list(head);
printf("\nInseting at first ....\n\n");
head = insert_begining(head,69);
print_list(head);
// printf("\nInseting at index ....\n\n");
// head = insert_by_index(head,628,2);
// print_list(head);
// printf("\nInseting at the end ....\n\n");
// head = insert_at_end(head,99);
// print_list(head);
// printf("\nInseting after a node ....\n\n");
// head = insert_after_node(head,third,555);
// print_list(head);
}