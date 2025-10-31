#include<bits/stdc++.h>
using namespace std;


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


void postOrder(s *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d->", root->data);

    }

}


void preOrder(s *root)
{
    if (root != NULL)
    {
        printf("%d->", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}


void inOrder(s*root){
if(root!=NULL){
    inOrder(root->left);
        printf("%d->", root->data);
        inOrder(root->right);
}
}


s*insertBST(s*root ,int data) {

    if(root==NULL){
        return create_node(data);
    }

    if(data>root->data){
        root->right = insertBST(root->right,data);

    }

   else if(data<root->data){
        root->left = insertBST(root->left,data);
    }
return root;
}






int main(){
    s*root=NULL;

    root = insertBST(root,10);
    insertBST(root,5);
    insertBST(root,3);
    insertBST(root,2);
    printf("In Order Tree: \n");
    inOrder(root);
    printf("\n");
    cout<<endl;
    printf("Post Order Tree: \n");
    postOrder(root);
    printf("\n");
    cout<<endl;
    printf("Pre Order Tree: \n");
    preOrder(root);
    cout<<endl;

}





































/*int main(){
    s*root=create_node(10);
    root->left= create_node(20);
    root->right= create_node(30);
    root->left->left= create_node(40);
    root->left->right= create_node(50);
    root->right=create_node(30);

    insertBST(root,545);
    printf("In Order Tree: \n");
    inOrder(root);
    printf("\n");
    cout<<endl;
    printf("Post Order Tree: \n");
    postOrder(root);
    printf("\n");
    cout<<endl;
    printf("Pre Order Tree: \n");
    preOrder(root);
    cout<<endl;

}
*/







/* void print_post_order_tree(s *root)
{
    if (root == NULL){ return;
    }// return likle seitar type lokte hobe
        print_post_order_tree(root->left);
        print_post_order_tree(root->right);
        printf("%d->", root->data);


}*/


/*void insertBST(s*& root, int data) {
    if (root == NULL) {
        root = create_node(data);
        return;
    }

    if (data < root->data) {
        insertBST(root->left, data);
    } else if (data > root->data) {
        insertBST(root->right, data);
    }
}
*/
