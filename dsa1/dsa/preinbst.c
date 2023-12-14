#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

TreeNode* buildTree(int preorder[], int inorder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) {
        return NULL;
    }

    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (!node) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    node->data = preorder[*preIndex];
    (*preIndex)++;

    if (inStart == inEnd) {
        node->left = node->right = NULL;
        return node;
    }

    int inIndex = search(inorder, inStart, inEnd, node->data);

    node->left = buildTree(preorder, inorder, inStart, inIndex - 1, preIndex);
    node->right = buildTree(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return node;
}

void printTreeStructure(TreeNode* root, int space) {
    if (root == NULL) {
        return;
    }

    space += 5;

    printTreeStructure(root->right, space);

    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    printTreeStructure(root->left, space);
}

void printTree(TreeNode* root) {
    printf("Tree Structure:\n");
    printTreeStructure(root, 0);
}

int main() {
    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int preorder[n], inorder[n];

    printf("Enter the Preorder Traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }

    printf("Enter the Inorder Traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    int preIndex = 0;
    TreeNode* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);

    printTree(root);

    return 0;
}