#include<stdio.h>
#include<limits.h>
int n;
int parent[100];
int root(int v) {
        while ( v != parent[v])
                v = parent[v];
        return v;
}

void quickUnion(int p, int q){
        int i = root(p);
        int j = root(q);
        parent[i] = j;
}

void kruskal(int adjMat[][n]) {
        for(int i = 0 ; i < n ; i++) {
                parent[i] = i;
        }
        int minCost = 0, edgeCount = 0;
        int min, u, v;
        while(edgeCount < n-1) {
                min = INT_MAX;
                u = -1; v = -1;
                for(int i = 0 ; i < n ; i++) {
                        for(int j = 0 ; j < n ; j++){
                                if(adjMat[i][j] < min){
                                        if(root(i) != root(j)){
                                                min = adjMat[i][j];
                                                u = i;
                                                v = j;
                                        }
                                }
                        }
                }
                if(u != -1 && v != -1){
                quickUnion(u, v);
                        minCost += min;
                        printf("\n Edge %d (%d, %d) => Cost : %d ", edgeCount++, u, v, min);

                }
        }

        printf("\n The Cost of the Minimum Spanning Tree is %d\n\n", minCost);
}

void main(){
        printf("\n Enter the no. of vertices in the graph: ");
        scanf("%d", &n);
        printf("\n Enter the weighted adjacency matrix of the graph: \n");
        int adjMat[n][n];
        for(int i = 0 ; i < n ; i++){
                for(int j = 0; j < n ; j++){
                        scanf("%d", &adjMat[i][j]);
                        if(adjMat[i][j] == 0)
                                adjMat[i][j] = INT_MAX;
                }
        }


        kruskal(adjMat);

}