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

// void preorder(s *root)
// {
//     if (root != NULL)
//     {
//         printf("%d->", root->data);
//         preorder(root->left);
//         preorder(root->right);
//     }
// }

void post_order(s *root)
{
    if (root != NULL)
    {
        post_order(root->left);
        post_order(root->right);
        printf("%d->", root->data);

    }
}
int main()
{
    // root node & other node
    s *p = create_node(4);
    s *p1 = create_node(1);
    s *p2 = create_node(6);
    s *p3 = create_node(5);
    s *p4 = create_node(2);

    // linking
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    post_order(p);
}
