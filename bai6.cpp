#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *createNode(int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node *insert(Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

int isBSTUtil(Node *root, int min, int max) {
    if (root == NULL) {
        return 1;
    }
    if (root->data <= min || root->data >= max) {
        return 0;
    }
    return isBSTUtil(root->left, min, root->data) && isBSTUtil(root->right, root->data, max);
}

int isBST(Node *root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    Node *root = NULL;
    int n, value;
    printf("Nhap so luong gia tri nut: ");
    scanf("%d", &n);
    if (n == 0) {
        printf("Cay la cay nhi phan tim kiem (BST).\n");
        return 0;
    }
    printf("Nhap gia tri cac nut: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }
    if (isBST(root)) {
        printf("Cay la cay nhi phan tim kiem (BST).\n");
    } else {
        printf("Cay khong phai la cay nhi phan tim kiem (BST).\n");
    }
    return 0;
}
