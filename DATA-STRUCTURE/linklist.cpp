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
        printf("%d\n",i->data);
        i=i->next;
    }

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

    return 0;



}