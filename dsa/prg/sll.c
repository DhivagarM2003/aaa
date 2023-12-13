#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void deleteElement(int value) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == value) {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found in the list\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void search(int value) {
    struct Node* temp = head;
    int position = 0;
    bool found = false;

    while (temp != NULL) {
        position++;
        if (temp->data == value) {
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (found) {
        printf("Value found at position %d\n", position);
    } else {
        printf("Value not found in the list\n");
    }
}

void display() {
    struct Node* temp = head;
    printf("Singly linked list: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int countElements() {
    struct Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    int choice, value, searchValue, deleteValue;

    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Delete an element\n");
        printf("4. Search for an element\n");
        printf("5. Display the list\n");
        printf("6. Count the number of elements\n");
        printf("7. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter the value to delete: ");
                scanf("%d", &deleteValue);
                deleteElement(deleteValue);
                break;
            case 4:
                printf("Enter the value to search: ");
                scanf("%d", &searchValue);
                search(searchValue);
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Number of elements in the list: %d\n", countElements());
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}