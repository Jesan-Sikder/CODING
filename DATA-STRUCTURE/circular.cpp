#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    

    struct node * next;
};
typedef struct node s;
void print(s*i){
    s*ptr=i;
    do
    {
        printf("element : %d\n",ptr->data);
        ptr = ptr->next;
    }while (ptr != i);
    
}
int main(){
    s*one =(s*)malloc(sizeof(s));
    s*two =(s*)malloc(sizeof(s));
    s*thi =(s*)malloc(sizeof(s));
    s*four =(s*)malloc(sizeof(s));
     one -> data = 1;
     one->next = two;
     two->data = 2;
     two ->next = thi;
     thi->data=3;
     thi->next = four;
     four->data=4;
     four->next = one; 


     print(one);



}