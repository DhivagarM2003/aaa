#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5
typedef struct {
    int* queue;
    int front;
    int rear;
    int itemCount;
} CircularQueue;
CircularQueue* createQueue() {
    CircularQueue* queue = (CircularQueue*) malloc(sizeof(CircularQueue));
    queue->queue = (int*) malloc(MAX_SIZE * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->itemCount = 0;
    return queue;
}
int isFull(CircularQueue* queue) {
    return (queue->front == 0 && queue->rear == MAX_SIZE - 1) ||
           (queue->front == queue->rear + 1);
}
int isEmpty(CircularQueue* queue) {
    return queue->front == -1;
}
void enqueue(CircularQueue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue item.\n");
        return;
    }
    if (queue->front == -1)
        queue->front = 0;
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->queue[queue->rear] = item;
    queue->itemCount++;
}
int dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue item.\n");
        return -1;
    }
    int item = queue->queue[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->itemCount--;
    if (queue->front > queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }
    return item;
}
void display(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    int i;
    printf("Queue: ");
    for (i = queue->front; i != queue->rear; i = (i + 1) % MAX_SIZE)
        printf("%d ", queue->queue[i]);
    printf("%d\n", queue->queue[i]);
}
int main() {
    CircularQueue* queue = createQueue();
    int opt;
    l:printf("\nChoose from following options \n1=>enqueue \n2=>dequeue \n3=>display \n0=>exit");
scanf("%d",&opt);
switch(opt)
{
case 1:
    {
        int n;
        printf("Enter the number:");
        scanf("%d",&n);
        enqueue(queue,n);
        goto l;
    }
case 2:
    {
       dequeue(queue);
       goto l;
    }
case 3:
    {
        display(queue);
        goto l;
    }
case 4:
    {
        free(queue->queue);
    free(queue);
    }
case 0:
    {
       break;
    }
}
}