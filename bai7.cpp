#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

typedef struct QueueNode {
    Node *treeNode;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    QueueNode *front, *rear;
} Queue;

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
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

Queue *createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue *q, Node *treeNode) {
    QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
    temp->treeNode = treeNode;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

Node *dequeue(Queue *q) {
    if (q->front == NULL) return NULL;
    QueueNode *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    Node *treeNode = temp->treeNode;
    free(temp);
    return treeNode;
}

int isEmpty(Queue *q) {
    return q->front == NULL;
}

int isCompleteBinaryTree(Node *root) {
    if (root == NULL) return 1;
    Queue *q = createQueue();
    int flag = 0;
    enqueue(q, root);
    while (!isEmpty(q)) {
        Node *current = dequeue(q);
        if (current->left) {
            if (flag) return 0;
            enqueue(q, current->left);
        } else {
            flag = 1;
        }
        if (current->right) {
            if (flag) return 0;
            enqueue(q, current->right);
        } else {
            flag = 1;
        }
    }
    return 1;
}

int main() {
    Node *root = NULL;
    int n, value;
    printf("Nhap so luong gia tri nut: ");
    scanf("%d", &n);
    printf("Nhap gia tri cac nut: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }
    if (isCompleteBinaryTree(root)) {
        printf("Cay la cay nh? phân hoàn ch?nh.\n");
    } else {
        printf("Cay khong phai la cay nh? phân hoàn ch?nh.\n");
    }
    return 0;
}
