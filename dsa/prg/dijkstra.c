#include <stdio.h>
#define INFINITY 99999
#define MAX 30
void Dijkstra(int Graph[MAX][MAX], int n, int start) {
        int cost[MAX][MAX], distance[MAX], pred[MAX];
        int visited[MAX], count, mindistance, nextnode, i, j;
        for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                        if (Graph[i][j] == 0)
                                cost[i][j] = INFINITY;

                        else
                                cost[i][j] = Graph[i][j];

        for (i = 0; i < n; i++) {
                distance[i] = cost[start][i];

                pred[i] = start;

                visited[i] = 0;
        }

        distance[start] = 0;
        visited[start] = 1;
        count = 1;
        while (count < n - 1) {
                mindistance = INFINITY;

                for (i = 0; i < n; i++)
                        if (distance[i] < mindistance && !visited[i]) {
                                mindistance = distance[i];

                                nextnode = i;

                        }

                visited[nextnode] = 1;
                for (i = 0; i < n; i++)
                        if (!visited[i])
                                if (mindistance + cost[nextnode][i] < distance[i]) {
                                        distance[i] = mindistance + cost[nextnode][i];

                                        pred[i] = nextnode;

                                }

                count++;

        }
        
        int dist[MAX],prev;
        for(int i=0; i < n; i++){
                if(i != start){
                        prev = pred[i];
                        j=-1;
                        dist[++j] = prev;
                        while(prev != start){
                                dist[++j] = pred[prev];
                                prev = pred[prev];
                        }
                        while(j >= 0){
                                printf("%d->",dist[j--]);
                        }
                        printf("%d",i);
                        printf(" = %d\n",distance[i]);
                }
        }
}
int main() {
        int Graph[MAX][MAX], i, j, n, u;
        printf("Enter no. of vertices : ");
        scanf("%d",&n);
        printf("\n Enter the adjacency matrix:\n ");
        for(int i=0; i<n;i++){
                for(int j=0;j<n;j++){
                        scanf("%d",&Graph[i][j]);
                }
        }
        printf("Enter source vertex : ");
        scanf("%d",&u);
        Dijkstra(Graph, n, u);

        return 0;
}