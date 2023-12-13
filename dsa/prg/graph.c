#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
int n;
bool isValidEdge(int u, int v, bool mstAdded[]){
        if(u == v)
                return false;
        else if (mstAdded[u] == true && mstAdded[v] == true)
                return false;
        else if (mstAdded[u] == false && mstAdded[v] == false)
                return false;
        else
                return true;
}

void prim(int adjMat[][n]){
        bool mstAdded[n];
        for(int i = 0 ; i < n ; i++){
                mstAdded[i] = false;
        }
        mstAdded[0] = true;
        int min,minCost = 0 ,edgeCount = 0;
        int u, v;
        while(edgeCount < n - 1) {
                min = INT_MAX;
                u = -1 ; v = -1;
                for(int i = 0 ; i < n ; i++){
                        for(int j = 0 ; j < n ; j++){
                                if(adjMat[i][j] < min){
                                        if(isValidEdge(i, j, mstAdded)){
                                                min = adjMat[i][j];
                                                u = i;
                                                v = j;
                                        }
                                }
                        }
                }

                if(u != -1  && v != -1) {
                        minCost += min;
                        printf("\n Edge %d (%d, %d) => Cost : %d ", edgeCount++, u, v, min);
                        mstAdded[u] = true; mstAdded[v] = true;
                }

        }
        printf("\n The Cost of the Minimum Spanning Tree is %d\n\n", minCost);
}

void main() {
        printf("\n Enter the no. of vertices in the graph: ");
        scanf("%d", &n);
        int adjMat[n][n];
        printf("\n Enter the weighted adjacency matrix of the graph: \n");
        for(int i = 0 ; i < n ; i++){
                for(int j = 0; j < n ; j++){
                        scanf("%d", &adjMat[i][j]);
                        if(adjMat[i][j] == 0)
                                adjMat[i][j] = INT_MAX;
                }
        }

        prim(adjMat);

}