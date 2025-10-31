#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node s;
s *create_node(int data)
{
    s *n;
    n = (s *)malloc(sizeof(s));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
int main()
{
    // root node & other node
    s *p = create_node(2);
    s *p1 = create_node(1);

    s *p2 = create_node(4);
    // linking
    p->left = p1;
    p->right = p2;
}
// int main()
// {
//     // root the first node
//     s *p;

//     p = (s *)malloc(sizeof(s));
//     p->data = 2;
//     p->left = NULL;
//     p->right = NULL;
//     // second node
//     s *p1;
//     p1 = (s *)malloc(sizeof(s));
//     p->data = 1;
//     p1->left = NULL;
//     p1->right = NULL;
//     // third node
//     s *p2;
//     p2 = (s *)malloc(sizeof(s));
//     p->data = 4;
//     p2->left = NULL;
//     p2->right = NULL;
//     // linking them
//     p->left = p1;
//     p->right = p2;
//     return 0;
// }