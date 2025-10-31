#include<stdio.h>
#include<stdlib.h>
 struct info{
    int a;
    char b;
    struct info * next;
};
typedef struct info I;
I*start;
void printll(){
    printf("Printing linked list\n");
    I*i=start;
    while(i!=NULL){
        printf("%d ",i->a);
        printf("%c\n",i->b);
        i = i-> next;
    }
}
void insertB()
{
    printf("Creating newnode at Beginning.\n");
    I*newnode = (I*)malloc(sizeof(I));
    int x; char y;
    printf("Enter data for newnode:\n");
    scanf("%d %c",&x,&y);
    newnode -> a=x;
    newnode -> b=y;
    newnode -> next = NULL;
    newnode -> next = start;
    start = newnode;
}
int main(){
    insertB();
    insertB();

    printll();
    return 0;
}
