#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NODES 100

struct Queue {
    int items[MAX_NODES];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX_NODES - 1) {
        printf("Queue is full\n");
        return;
    }

    if (q->front == -1)
        q->front = 0;

    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        exit(1);
    } else {
        item = q->items[q->front];
        q->front++;

        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
        return item;
    }
}

void bfs(int graph[MAX_NODES][MAX_NODES], int start, int n) {
    struct Queue q;
    initQueue(&q);

    bool visited[MAX_NODES] = {false};
    visited[start] = true;
    printf("BFS Traversal starting from node %d: ", start);

    printf("%d ", start);
    enqueue(&q, start);

    while (!isEmpty(&q)) {
        int current = dequeue(&q);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] && !visited[i]) {
                printf("%d ", i);
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &n);

    int graph[MAX_NODES][MAX_NODES];
    printf("Enter the adjacency matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int startNode;
    printf("Enter the starting node for BFS: ");
    scanf("%d", &startNode);

    if (startNode < 0 || startNode >= n) {
        printf("Invalid starting node\n");
        return 1;
    }

    bfs(graph, startNode, n);

    return 0;
}

