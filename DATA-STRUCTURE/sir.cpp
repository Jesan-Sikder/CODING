#include<stdio.h>
#include<stdlib.h>
struct student
{
    int a;
    struct student *next;
};
typedef struct student s;

s *start=NULL;
void print()
{
    s *i=start;
    while(i!=NULL)
    {
        printf("%d",i->a);
        i=i->next;
    }
    printf("\n");
}
void insertB()
{
    printf("Inserting begining: \n");
    s *newnode=(s*)malloc(sizeof(s));
    int data;
    printf("Insert data part: ");
    scanf("%d",&data);
    newnode->a=data;
    newnode->next=NULL;
    newnode->next=start;
    start=newnode;

}
void insertLast()
{
    if(start==NULL)
    {
        insertB();
    }
    else
    {
        printf("Inserting Last position: \n");
    s *newnode=(s*)malloc(sizeof(s));
    int data;
    printf("Insert data part: ");
    scanf("%d",&data);
    newnode->a=data;
    newnode->next=NULL;
    s *i=start;
    while(i->next!=NULL)
    {
        i=i->next;
    }
    i->next=newnode;
    }


}
int main()
{
    insertB();
    print();
    insertLast();
    print();

    return 0;
}

