#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
void mirror(struct Node *node)
{
    if (node == NULL)
    return;
    else
    {
        struct node *temp;
        mirror(node->left);
        mirror(node->right);
        temp=node->left;
        node->left = node->right;
        node->right=temp;    
    }
}
int countnodes(struct Node *root)
{
    int count = 0;
    if (root != NULL)
    {
        countnodes(root->left);
        count++;
        countnodes(root->right);
    }
    return count;
}
struct Node *cloneBinaryTree(struct Node *root)
{
    if (root == NULL)
    return NULL;
    struct Node *NNew = newNode(root->data);
    NNew->left = cloneBinaryTree(root->left);
    NNew->right = cloneBinaryTree(root->right);
    return NNew;
}
void Inorder(struct Node *node)
{
    if (node == NULL)
    return;
    Inorder(node->left);
    printf("%d", node->data);
    Inorder(node->right);
}
int main()
{
    struct Node *clone;
    struct Node *root = newNode(6);
    root->left = newNode(7);
    root->right = newNode(3);
    root->left->left = newNode(8);
    root->left->right = newNode(9);
    printf("\n Inorder Traversal of original tree \n");
    Inorder(root);
    mirror(root);
    printf("\n Inorder Traversal of Mirrored tree \n");
    Inorder(root);
    clone = cloneBinaryTree(root);
    printf("\n Inorder Traversal of the Clone tree is \n");
    Inorder(clone);
    printf("\n Number of nodes in Tree = %d", countnodes(root));
    return 0;
}