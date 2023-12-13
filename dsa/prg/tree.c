#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100
#define COUNT 10
struct node {
        int data;
        struct node* left;
        struct node* right;
};

struct node* newnode(int data) {
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->data = data;
        temp->left = temp->right = 0;
        return temp;
}

struct node* insert(struct node* root, int data) {
        if (root == 0) {
                return newnode(data);
        } else if (data < root->data) {
                root->left = insert(root->left, data);
        } else {
                root->right = insert(root->right, data);
        }
        return root;
}
void print(struct node* root, int space) {
        if (root == NULL) {
                return;
        }
        space += COUNT;
        print(root->right, space);
        printf("\n");
        for (int i = COUNT; i < space; i++) {
                printf(" ");
        }
        printf("%d\n", root->data);
        print(root->left, space);
}

void display(struct node* root) {
        printf("Binary Tree: \n");
        print(root, 0);
}
int main() {
        struct node* root = 0;
        char pre[MAX], inf[MAX];
        printf("enter the preorder expression : ");
        scanf("%[^\n]s", pre);
        printf("enter the inorder expression : ");
        scanf(" %[^\n]s", inf);

        int num = 0;
        for (int i = 0; pre[i] != '\0'; i++) {
                if (pre[i] == ' ') {
                        continue;
                }
                while (isdigit(pre[i])) {
                        num = num * 10 + (pre[i] - '0');
                        i++;
                }
                if(num!=0)
                        root = insert(root, num);
                num = 0;
        }
        display(root);
}