#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

/TreeNode createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}*/

int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

TreeNode* buildBST(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex)
 {
   TreeNode* node = (TreeNode*)malloc(sizeof(struct newnode));
   if(inStart>inEnd)
   {
       return NULL;
   }
   if(node == NULL)
   {
       printf("\n Memory allocation failed");
       exit(1);
   }
   node->data=postorder[*postindex];
   (*postindex)--;
   if(inStart == inEnd)
   {
       node->left=newnode->right=NULL;
       return node;
   }
   int inindex=search(inorder,inStart,inEnd,node->data);

   node->left = buildtree(inorder,postorder,inStart,inindex-1,postindex);
   node->right = buildtree(inorder,postorder,inindex+1,inEnd,postindex);
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

int main()
 {
    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int inorder[n], postorder[n];

    printf("Enter the Inorder Traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    printf("Enter the Postorder Traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &postorder[i]);
    }

    int postIndex = n - 1;
    TreeNode* root = buildBST(inorder, postorder, 0, n - 1, &postIndex);

    printTree(root)
    return 0; 
    }