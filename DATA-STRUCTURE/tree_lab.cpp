#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node s;
s*create_node(int data){

    s*newnode;
    newnode=(s*)malloc(sizeof(s));
    newnode->data=data;
    newnode->left = NULL;
    newnode->right= NULL;
    return newnode;

}
void print_post_order_tree(s *root)
{
    if (root != NULL)
    {
        print_post_order_tree(root->left);
        print_post_order_tree(root->right);
        printf("%d->", root->data);

    }

}
void print_preorder_tree(s *root)
{
    if (root != NULL)
    {
        printf("%d->", root->data);
        print_preorder_tree(root->left);
        print_preorder_tree(root->right);
    }
}
//  void print_post_order_tree(s *root)
// {
//     if (root == NULL){ return;
//     }// return likle seitar type lokte hobe
//         print_post_order_tree(root->left);
//         print_post_order_tree(root->right);
//         printf("%d->", root->data);


// }
void print_in_order_tree(s*root){
if(root!=NULL){
    print_in_order_tree(root->left);
        printf("%d->", root->data);
        print_in_order_tree(root->right);
}
}

int main(){
    s*root=create_node(10);
    root->left= create_node(20);
    root->right= create_node(30);
    root->left->left= create_node(40);
    root->left->right= create_node(50);
    root->right=create_node(30);
    printf("Printing the in order tree\n");
    print_in_order_tree(root);
    printf("\n");
    printf("Printing the post order tree\n");
    print_post_order_tree(root);
    printf("\n");
    printf("Printing the pre order tree\n");
    print_preorder_tree(root);

}