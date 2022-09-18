#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{

    char data;
    struct node *left;
    struct node *right;
};

struct node *create_node(char x)
{
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node* create_tree()
{
    char x ;
    scanf("\n%c", &x);
    if (x == '*')
        return NULL;
    struct node *newnode = create_node(x);
    printf("Enter the left data : (*) for no node\n");
        newnode->left = create_tree();
    printf("Enter the right data : (*) for no node\n");
        newnode->right = create_tree();
    return newnode;
}

void Preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%c ", root->data);
    Preorder(root->left);
    Preorder(root->right);
}
void Inorder(struct node *root)
{
    if (root == NULL)
        return;
    Inorder(root->left);
    printf("%c ", root->data);
    Inorder(root->right);
}
void Postorder(struct node *root)
{
    if (root == NULL)
        return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%c ", root->data);
}
bool isSymmetric(struct node *root1, struct node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 && root2 && root1->data == root2->data)
        return isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left);
    return false;
} 

// Write a C program that uses functions to perform the following:
// a) Create a binary search tree of characters.
// b) Traverse the above Binary search tree recursively in Preorder, Inorder, and
// Postorder
// c) Write a function for testing two given trees are symmetric or not

int main()
{
    
    //::::::::::::::: Create a binary search tree of characters.::::::::::::::::
    
    printf("Enter the root data for BST : (*) for no node\n");
    struct node *root = create_tree();

    //::::::::::::::::: Traverse the above Binary search tree recursively in Preorder, Inorder, and Postorder ::::::::::

    printf("PREORDER :\n");
    Preorder(root);
    printf("\n");
    printf("INORDER :\n");
    Inorder(root);
    printf("\n");
    printf("POSTORDER :\n");
    Postorder(root);
    printf("\n");
    
    
    // :::::::::::: testing two given trees are symmetric or not :::::::::::::::::::::::::
    printf("Enter the root1 data : (*) for no node\n");
    struct node *root1=create_tree();
    printf("Enter the root2 data : (*) for no node\n");
    struct node *root2=create_tree();

    if (isSymmetric(root1, root2))
        printf("YES, THE TWO TREES ARE SYMMETRIC.");
    else
        printf("NO, THE TWO TREES ARE NOT SYMMETRIC.");

    return 0;
}

