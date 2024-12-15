#include <stdio.h>
#include <stdlib.h>

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

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int search(Node *root, int key) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == key) {
        return 1;
    }
    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

int main() {
    Node *root = NULL;
    int chonce, value, key;
    do {
        printf("\n1. Chen gia tri\n2. Duyet cay (Inorder)\n3. Tim kiem gia tri\n4. Thoat\nChon: ");
        scanf("%d", &chonce);

        switch (chonce) {
            case 1:
                printf("Nhap gia tri: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Duyet cay theo thu tu inorder: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &key);
                if (search(root, key)) {
                    printf("Gia tri %d ton tai trong cay.\n", key);
                } else {
                    printf("Gia tri %d khong ton tai trong cay.\n", key);
                }
                break;
            case 4:
                printf("Thoat chuong trinh.\n");
                exit(0);
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (1 == 1);
    return 0;
}
