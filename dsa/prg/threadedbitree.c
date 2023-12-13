#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int isThreaded; 
};

typedef struct Node Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->isThreaded = 0;  
    return newNode;
}

void morrisInOrder(Node* root) {
    Node* current = root;
    Node* predecessor;

    while (current != NULL) {
        if (current->left == NULL) {
            printf("%d ", current->data);

            if (current->isThreaded) {
                current = current->right;
            } else {
                current = current->right;
            }
        } else {
            predecessor = current->left;
            while (predecessor->right != NULL && predecessor->right != current) {
                predecessor = predecessor->right;
            }

            if (predecessor->right == NULL) {
                predecessor->right = current;
                predecessor->isThreaded = 1; 
                current = current->left;
            } else {
                predecessor->right = NULL;
                predecessor->isThreaded = 0;
                printf("%d ", current->data);

                if (current->isThreaded) {
                    current = current->right;
                } else {
                    current = current->right;
                }
            }
        }
    }
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    Node* current = root;
    Node* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            if (current->left == NULL) {
                current->left = createNode(data);
                current->isThreaded = 1; 
                current->left->right = current;  
                break;
            }
            current = current->left;
        } else if (data > current->data) {
            if (current->isThreaded || current->right == NULL) {
                Node* newNode = createNode(data);
                newNode->left = current;
                newNode->isThreaded = 1; 
                current->right = newNode; 
                break;
            }
            current = current->right;
        } else {
            break;
        }
    }

    return root;
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;
    int n, data;

    printf("Enter the number of nodes in the threaded binary tree: ");
    scanf("%d", &n);

    printf("Enter the nodes of the threaded binary tree:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("In-order traversal using Morris Traversal:\n");
    morrisInOrder(root);
    printf("\n");

    // Free memory
    freeTree(root);

    return 0;
}
