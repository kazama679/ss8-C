#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node *insert(Node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }
    return root;
}

// dau 
void displayTree(Node *root)
{
    if(root != NULL){
        printf("%d\t", root->data);
        displayTree(root->left);
        displayTree(root->right);
    }
}

// giua
void displayTreeGiua(Node *root)
{
    if(root != NULL){
    	displayTreeGiua(root->left);
        printf("%d\t", root->data);
        displayTreeGiua(root->right);
    }
}

// cuoi 
void displayTreeCuoi(Node *root)
{
    if(root != NULL){
    	displayTreeCuoi(root->left);
        displayTreeCuoi(root->right);
        printf("%d\t", root->data);
    }
}

int main()
{
    Node *tree = NULL;

    tree = insert(tree, 5);
    tree = insert(tree, 3);
    tree = insert(tree, 7);
    tree = insert(tree, 2);
    tree = insert(tree, 4);
    tree = insert(tree, 6);
    tree = insert(tree, 8);

    printf("\nCau truc cay nhi phan dau:\n");
    displayTree(tree);
    printf("\nCau truc cay nhi phan giua:\n");
    displayTreeGiua(tree);
    printf("\nCau truc cay nhi phan cuoi:\n");
    displayTreeCuoi(tree);

    return 0;
}
