#include <stdio.h>
#include <stdlib.h>
struct Node {
        int data;
        struct Node* prev;
        struct Node* next;
};
struct Node* createNode(int data) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
                printf("Memory allocation failed!\n");
                exit(1);
        }
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;
        return newNode;
}
void insertAtBeginning(struct Node** head, int data) {
        struct Node* newNode = createNode(data);
        if (*head == NULL) {
                newNode->next = newNode;
                newNode->prev = newNode;
                *head = newNode;
        } else {
                struct Node* tail = (*head)->prev;
                newNode->next = *head;
                (*head)->prev = newNode;
                newNode->prev = tail;
                tail->next = newNode;
                *head = newNode;
        }
}
void insertAtEnd(struct Node** head, int data) {
        struct Node* newNode = createNode(data);
        if (*head == NULL) {
                newNode->next = newNode;
                newNode->prev = newNode;
                *head = newNode;
        } else {
                struct Node* tail = (*head)->prev;
                newNode->next = *head;
                (*head)->prev = newNode;
                newNode->prev = tail;
                tail->next = newNode;
        }
}
void insertBeforeElement(struct Node** head, int data, int key) {
        struct Node* newNode = createNode(data);
        if (*head == NULL) {
                printf("List is empty, cannot insert before element %d\n", key);
                return;
        }
        struct Node* current = *head;
        do {
                if (current->data == key) {
                        newNode->next = current;
                        newNode->prev = current->prev;
                        current->prev->next = newNode;
                        current->prev = newNode;
                        if (current == *head) {
                                *head = newNode;
                        }
                        return;
                }
                current = current->next;
        } while (current != *head);
        printf("Element %d not found in the list.\n", key);
        free(newNode);
}
void insertAfterElement(struct Node** head, int data, int key) {
        struct Node* newNode = createNode(data);
        if (*head == NULL) {
                printf("List is empty, cannot insert after element %d\n", key);
                return;
        }
        struct Node* current = *head;
        do {
                if (current->data == key) {
                        newNode->next = current->next;
                        newNode->prev = current;
                        current->next->prev = newNode;
                        current->next = newNode;
                        return;
                }
                current = current->next;
        } while (current != *head);
        printf("Element %d not found in the list.\n", key);
        free(newNode);
}
void deleteNode(struct Node** head, int key) {
        if (*head == NULL) {
                printf("List is empty, cannot delete element %d\n", key);
                return;
        }
        struct Node* current = *head;
        do {
                if (current->data == key) {
                        current->prev->next = current->next;
                        current->next->prev = current->prev;
                        if (current == *head) {
                                *head = current->next;
                        }
                        free(current);
                        return;
                }
                current = current->next;
        } while (current != *head);
        printf("Element %d not found in the list.\n", key);
}
void printList(struct Node* head) {
        if (head == NULL) {
                printf("List is empty.\n");
                return;
        }
        struct Node* current = head;
        do {
                printf("%d -> ", current->data);
                current = current->next;
        } while (current != head);
        printf("%d (Head)\n", head->data);
}
int main() {
        int ch,n,n1;
        struct Node* head = NULL;
        printf("\n1.addstart\t2.addend\t3.addbefore\t4.addafter\t5.delete\t6.display");
start:{
              printf("\nEnter your choice:");
              scanf("%d",&ch);
              if(ch==1)
              {
                      printf("Enter element to be added:");
                      scanf("%d",&n);
                      insertAtBeginning(&head,n);
              }
              else if(ch==2)
              {
                      printf("Enter element to be added:");
                      scanf("%d",&n);
                      insertAtEnd(&head,n);
              }
              else if(ch==3)
              {
                      printf("Enter element to be added and the element before which it has to be added:");
                      scanf("%d %d",&n,&n1);
                      insertBeforeElement(&head,n,n1);
              }
              else if(ch==4)
              {
                      printf("Enter element to be added and the element after which it has to be added:");
                      scanf("%d %d",&n,&n1);
                      insertBeforeElement(&head,n,n1);
              }
              else if(ch==5)
              {
                      printf("Enter element to be deleted:");
                      scanf("%d",&n);
                      deleteNode(&head,n);
              }
              else if(ch==6)
              {
                      printList(head);
              }
              goto start;
      }
      struct Node* current = head;
      do {
              struct Node* temp = current;
              current = current->next;
              free(temp);
      } while (current != head);
      return 0;
}