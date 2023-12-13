#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NODES 100

void dfs(int graph[MAX_NODES][MAX_NODES], int current, bool visited[MAX_NODES], int n) {
    printf("%d ", current);
    visited[current] = true;

    for (int i = 0; i < n; i++) {
        if (graph[current][i] && !visited[i]) {
            dfs(graph, i, visited, n);
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
    printf("Enter the starting node for DFS: ");
    scanf("%d", &startNode);

    if (startNode < 0 || startNode >= n) {
        printf("Invalid starting node\n");
        return 1;
    }

    bool visited[MAX_NODES] = {false};
    printf("DFS Traversal starting from node %d: ", startNode);
    dfs(graph, startNode, visited, n);

    return 0;
}

