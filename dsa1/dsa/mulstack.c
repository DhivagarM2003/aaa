#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct MultiStack {
    int *arr;
    int *top;
    int *next;
    int freeTop;
};

void init(struct MultiStack *ms, int n, int k) {
    ms->arr = (int *)malloc(sizeof(int) * n);
    ms->top = (int *)malloc(sizeof(int) * k);
    ms->next = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < k; i++)
        ms->top[i] = -1;

    ms->freeTop = 0;
    for (int i = 0; i < n - 1; i++)
        ms->next[i] = i + 1;
    ms->next[n - 1] = -1;
}

void push(struct MultiStack *ms, int k, int data) {
    if (ms->freeTop == -1) {
        printf("Stack Overflow\n");
        return;
    }

    int i = ms->freeTop;
    ms->freeTop = ms->next[i];
    ms->next[i] = ms->top[k];
    ms->top[k] = i;
    ms->arr[i] = data;
}

int pop(struct MultiStack *ms, int k) {
    if (ms->top[k] == -1) {
        printf("Stack %d Underflow\n", k);
        return -1;
    }

    int i = ms->top[k];
    ms->top[k] = ms->next[i];
    ms->next[i] = ms->freeTop;
    ms->freeTop = i;
    return ms->arr[i];
}

int main() {
    int n, k;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the number of stacks: ");
    scanf("%d", &k);

    struct MultiStack ms;
    init(&ms, n, k);

    int choice, data, stackNum;
    while (1) {
        printf("\nChoose operation:\n");
        printf("1. Push into a Stack\n");
        printf("2. Pop from a Stack\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the stack number (0-%d): ", k - 1);
                scanf("%d", &stackNum);
                if (stackNum < 0 || stackNum >= k) {
                    printf("Invalid stack number\n");
                    break;
                }
                printf("Enter data to push into Stack %d: ", stackNum);
                scanf("%d", &data);
                push(&ms, stackNum, data);
                break;
            case 2:
                printf("Enter the stack number (0-%d): ", k - 1);
                scanf("%d", &stackNum);
                if (stackNum < 0 || stackNum >= k) {
                    printf("Invalid stack number\n");
                    break;
                }
                data = pop(&ms, stackNum);
                if (data != -1)
                    printf("Popped element from Stack %d: %d\n", stackNum, data);
                break;
            case 3:
                printf("Exiting...\n");
                free(ms.arr);
                free(ms.top);
                free(ms.next);
                exit(0);
            default:
                printf("Invalid choice, please enter a valid number.\n");
        }
    }

    return 0;
}
