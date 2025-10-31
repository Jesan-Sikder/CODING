#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    
    struct node * prev;
    struct node * next;


};
typedef struct node s;
void print(s*i){
    while(i != NULL){
        printf("element : %d\n", i->data);
        // printf("element : %c\n", i->c);

        i=i->next;
    }
}
int main(){
    s*a=(s*)malloc(sizeof(s));
    s*b=(s*)malloc(sizeof(s));
    s*c=(s*)malloc(sizeof(s));

    a->data=1;
    a->next= b;
    b->prev =a;
    b->data=2;
    b->next=c;
    c->prev=b;
    c->data=3;
    c->next=NULL;
    print(a);


}